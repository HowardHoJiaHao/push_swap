# push_swap

> 42 Common Core · Rank 02

Sorts a list of integers using two stacks and a limited set of operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`), aiming for the smallest possible number of moves.

## Approach
- Input parsing with full validation (non-numeric values, overflow, duplicates)
- Values are indexed (normalised) before sorting
- Small stacks (≤ 5) use hard-coded optimal sorts
- Larger stacks use a **cost-based greedy algorithm**: push elements to stack B, then for each element compute the rotation cost in both stacks and re-insert the cheapest one into A

## Key concepts
Algorithm design, time complexity / Big-O, linked-list stacks.

## Usage
```bash
make
./push_swap 3 2 5 1 4
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker_linux $ARG
```
