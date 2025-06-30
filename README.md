# Push_swap

![Demo](https://github.com/Ateibuzena/PUSH_SWAP/blob/main/visualizer.gif)


Push_swap is a sorting project that involves implementing and optimizing an algorithm to sort a stack of integers using two stacks and a limited set of instructions. This project is designed to teach and evaluate optimization and algorithmic skills.

## Description

The goal of *push_swap* is to sort a list of numbers in stack `a` using a second stack `b` and a specific set of instructions. The number of moves should be minimized to optimize the solution. The instructions you can use are:

- `sa` : swap the first two elements in stack `a`.
- `sb` : swap the first two elements in stack `b`.
- `ss` : swap the first two elements in both stacks `a` and `b`.
- `pa` : push the first element from stack `b` to stack `a`.
- `pb` : push the first element from stack `a` to stack `b`.
- `ra` : rotate all elements in stack `a` upwards.
- `rb` : rotate all elements in stack `b` upwards.
- `rr` : rotate all elements in both stacks `a` and `b` upwards.
- `rra` : rotate all elements in stack `a` downwards.
- `rrb` : rotate all elements in stack `b` downwards.
- `rrr` : rotate all elements in both stacks `a` and `b` downwards.

## File Structure

The project file structure is as follows:

```
push_swap/
│
├── src/
│   ├── push_swap.c              # Main file for the main project
│   ├── handle              
│   │   ├── ft_inits.c            
│   │   ├── ft_prints.c
│   │   ├── ft_stacks.c
│   ├── moves
│   │   ├── ft_push.c
│   │   ├── ft_reverse.c
│   │   ├── ft_rotate.c
│   │   ├── ft_swap.c
│   ├── steps
│   │   ├── ft_steps.c
│   │   ├── ft_intermediate_steps.c
│   ├── utils
│   │   ├── ft_check_args.c
│   │   ├── ft_immediate_predecessor.c
│   │   ├── ft_isordered.c
│   │   ├── ft_join.c
│   │   ├── ft_math.c
│   │   ├── ft_min_max.c
│   │   ├── ft_free.c
│   │   ├── ft_sort_arrays.c
│   └── bonus/
│       ├── checker.c           # Main file for the bonus
│
├── objs/                     # Directory for main project objects when execute `make`
├── objs_bonus/               # Directory for bonus objects when execute `make bonus`
├── Makefile                  # Makefile
└── pushlibft.h               # Library
```

## Installation

1. Clone the repository to your machine.
2. Navigate to the main directory.
3. Run `make` to compile the main project or `make bonus` to compile the bonus version.
4. The executable file `push_swap` will be available in the root directory.

## Usage

To run the program:

```bash
./push_swap <numbers_to_sort>
```

Example:

```bash
./push_swap 3 2 5 1 4
```

This will output the optimal sequence of operations required to sort the stack.

## Implementation

The project uses a cost-based algorithm that sorts the numbers in descending order in stack `b`, selecting the optimal path to minimize the number of moves. This approach ensures step optimization for the given set size.

## Bonus

The bonus version includes a visual check of the moves performed in the project. This additional functionality can be executed using the `checker` file, which receives `push_swap` instructions and verifies if the result is correct.

```bash
./checker <numbers_to_sort>
```

## Author

Ana Zubieta
