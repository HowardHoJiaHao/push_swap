# push_swap

> 42 Common Core · Rank 02

## Introduction
Push_swap is a 42 project that involves sorting a list of integers using 2 stacks (they can be any data structure, e.g. an array or a linked list in C; this version uses linked lists) using the least possible operations (or moves). This project introduces the concept of Big O notation in computational algorithm efficiency. In this case, it is the time complexity: how many operations (or moves) it takes to sort the integers as a function of the input size.

At the start, stack **a** holds the numbers (the first argument is on top) and stack **b** is empty. At the end, all numbers must be back in **a**, sorted in ascending order (smallest on top), with **b** empty. The program prints the operations it uses, one per line.

## Operations allowed
| Code | Instruction | Action |
|:--:|---|---|
| `sa` | swap a | swaps the 2 top elements of stack a |
| `sb` | swap b | swaps the 2 top elements of stack b |
| `ss` | swap a + swap b | both `sa` and `sb` (not needed by this program) |
| `pa` | push a | moves the top element of stack b to the top of stack a |
| `pb` | push b | moves the top element of stack a to the top of stack b |
| `ra` | rotate a | shifts all elements of stack a up by one: the first becomes the last |
| `rb` | rotate b | shifts all elements of stack b up by one: the first becomes the last |
| `rr` | rotate a + rotate b | both `ra` and `rb` |
| `rra` | reverse rotate a | shifts all elements of stack a down by one: the last becomes the first |
| `rrb` | reverse rotate b | shifts all elements of stack b down by one: the last becomes the first |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb` |

## Algorithm used
Typical in-place sorting algorithms such as bubble sort, insertion sort and selection sort can't be used directly in this exercise because of its limitations: 1) only 2 stacks can be used, and 2) only the operations above are allowed. The project also limits the maximum number of operations for certain input sizes:

- 3 numbers: no more than 3 operations
- 5 numbers: no more than 12 operations
- 100 numbers: no more than 700 operations
- 500 numbers: no more than 5,500 operations

This program works in these steps:

1. **Parsing** – All arguments are joined and split on spaces, so `1 2 3`, `"1 2 3"` and `"1 2" 3` all work. Each value must be a whole number with an optional `+` or `-`, fit in an `int`, and appear only once. If the list is already sorted, nothing is printed.
2. **Indexing** – Every value is replaced by its rank (0 for the smallest, n-1 for the largest), so the algorithm works the same for any values, including negatives.
3. **Small lists (2 to 5 numbers)** – Hard-coded sorts:
   - 2 numbers: `sa` if needed.
   - 3 numbers: one of five fixed cases, at most 2 operations.
   - 4 or 5 numbers: push the smallest number to b (rotating whichever way is shorter) until 3 are left, sort those 3, then `pa` everything back.
4. **Larger lists** – Three phases:
   1. **Pre-sort into b.** The smallest and the largest numbers stay in a; everything else is pushed to b in chunks so that b is already roughly ordered. Up to 100 numbers use two halves (the upper half is pushed and rotated to the bottom of b with `rb`). Above 100, four quarters are used, the middle two first.
   2. **Cheapest insert back into a.** For every number in b, count the moves needed to bring it to the top of b (`rb` or `rrb`, whichever is shorter) and to rotate a so it lands in the right place (`ra` or `rra`). When both stacks turn the same way, the moves are shared with `rr` / `rrr`. The cheapest number is moved with `pa`, and this repeats until b is empty.
   3. **Final rotation.** a is rotated until the smallest number is on top.

## Performance
Measured on random input, with every result checked by 42's `checker_linux` (all **OK**):

| Numbers | Operations | Limit |
|:--:|:--:|:--:|
| 3 | at most 2 (all 6 orders tested) | 3 |
| 5 | at most 10 (200 random runs) | 12 |
| 100 | average 616, worst 686 (30 runs) | 700 |
| 500 | average 4,385, worst 4,867 (30 runs) | 5,500 |

## Error handling
| Input | Result |
|---|---|
| No arguments | Prints nothing |
| Already sorted | Prints nothing |
| Not a number (`1 2 a`, a lone `-`) | `Error` on standard error, exit status `1` |
| Outside the `int` range (`2147483648`) | `Error`, exit status `1` |
| Duplicate numbers (`1 2 1`) | `Error`, exit status `1` |
| Empty string or only spaces (`""`) | `Error`, exit status `1` |

## Clone and Compile
```bash
git clone https://github.com/HowardHoJiaHao/push_swap.git
cd push_swap
make
```

Other targets: `make clean` (remove object files), `make fclean` (also remove `push_swap`) and `make re` (rebuild from scratch).

## Run
```bash
./push_swap <numbers to sort>
```

Example:
```bash
./push_swap 23 5 8 -2 1 28
```

Result (operations needed to sort stack a):
```
pb
pb
pb
rb
ra
pb
ra
ra
pa
ra
pa
ra
pa
pa
ra
ra
ra
```

Feel free to test with however many numbers you want. For example, to count the operations for 100 random numbers:
```bash
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

To check the result is correctly sorted, use the `checker_linux` program from the 42 project page (not included in this repository):
```bash
./push_swap $ARG | ./checker_linux $ARG    # prints OK
```
