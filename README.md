# push_swap

> 42 Common Core · Rank 02

The purpose of this project is to sort a list of integers using two stacks and a limited set of instructions, while printing the **smallest possible number of instructions**. It is an exercise in sorting algorithms, algorithm design and complexity.

## The rules
There are two stacks, **a** and **b**. At the start, **a** holds the numbers (the first argument is on top) and **b** is empty. The goal is to end with all numbers in **a**, sorted in ascending order (smallest on top), and **b** empty.

The only allowed instructions are:

| Instruction | What it does |
|:--:|---|
| `sa` / `sb` | Swap the first two elements of stack a / b |
| `ss` | `sa` and `sb` at the same time (not needed by this program) |
| `pa` | Take the top element of b and put it on top of a |
| `pb` | Take the top element of a and put it on top of b |
| `ra` / `rb` | Rotate a / b up: the first element becomes the last |
| `rr` | `ra` and `rb` at the same time |
| `rra` / `rrb` | Reverse rotate a / b: the last element becomes the first |
| `rrr` | `rra` and `rrb` at the same time |

`push_swap` prints the instructions it uses, one per line.

## Usage
```bash
./push_swap 3 2 5 1 4
```
The numbers can also be given as one string (`"3 2 5 1 4"`) or a mix of both (`"3 2" 5 1 4`).

## How it works
1. **Parsing** – All arguments are joined and split on spaces. Each value must be a whole number with an optional `+` or `-`, fit in an `int`, and appear only once. If the list is already sorted, nothing is printed.
2. **Indexing** – Every value is replaced by its rank (0 for the smallest, n-1 for the largest), so the algorithm works the same for any values, including negatives.
3. **Small lists (2 to 5 numbers)** – Hard-coded sorts:
   - 2 numbers: `sa` if needed.
   - 3 numbers: one of five fixed cases, at most 2 instructions.
   - 4 or 5 numbers: push the smallest number to b (rotating whichever way is shorter) until 3 are left, sort those 3, then `pa` everything back.
4. **Larger lists** – A three-step strategy:
   1. **Pre-sort into b.** The smallest and the largest numbers stay in a; everything else is pushed to b in chunks so that b is already roughly ordered. Up to 100 numbers use two halves (the upper half is pushed and rotated to the bottom of b with `rb`). Above 100, four quarters are used, the middle two first.
   2. **Cheapest insert back into a.** For every number in b, count the moves needed to bring it to the top of b (`rb` or `rrb`, whichever is shorter) and to rotate a so it lands in the right place (`ra` or `rra`). When both stacks turn the same way, the moves are shared with `rr` / `rrr`. The cheapest number is moved with `pa`, and this repeats until b is empty.
   3. **Final rotation.** a is rotated until the smallest number is on top.

## Performance
Measured on random input, with every result checked by 42's `checker_linux` (all **OK**):

| Numbers | Instructions | Limit for full marks |
|:--:|:--:|:--:|
| 3 | at most 2 (all 6 orders tested) | 3 |
| 5 | at most 10 (200 random runs) | 12 |
| 100 | average 616, worst 686 (30 runs) | 700 |
| 500 | average 4385, worst 4867 (30 runs) | 5500 |

## Error handling
| Input | Result |
|---|---|
| No arguments | Prints nothing |
| Already sorted | Prints nothing |
| Not a number (`1 2 a`, a lone `-`) | `Error` on standard error, exit status `1` |
| Outside the `int` range (`2147483648`) | `Error`, exit status `1` |
| Duplicate numbers (`1 2 1`) | `Error`, exit status `1` |
| Empty string or only spaces (`""`) | `Error`, exit status `1` |

## Clone
Clone the repository:
```bash
git clone https://github.com/HowardHoJiaHao/push_swap.git
```

## Compile and Run
To compile, `cd` into the cloned directory and run:
```bash
make
```

This builds the `push_swap` executable. Other targets: `make clean` (remove object files), `make fclean` (also remove `push_swap`) and `make re` (rebuild from scratch).

To run the program:
```bash
./push_swap 3 2 5 1 4
```

To count the instructions for 100 random numbers:
```bash
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

To check the result is correctly sorted, use the `checker_linux` program from the 42 project page (not included in this repository):
```bash
./push_swap $ARG | ./checker_linux $ARG    # prints OK
```
