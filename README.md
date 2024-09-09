# PUSH_SWAP

**Push Swap** is a sorting algorithm project designed to efficiently sort a stack of integers using a minimal set of operations. The goal is to implement two stacks, `A` and `B`, and sort stack `A` using a predefined set of operations, while keeping stack `B` as a temporary storage.

The challenge lies in creating an algorithm that can sort the stack with the fewest number of operations possible, using the following allowed commands:

- **`sa` (swap a):** Swap the first two elements of stack A.
- **`sb` (swap b):** Swap the first two elements of stack B.
- **`ss`:** Perform `sa` and `sb` simultaneously.
- **`pa` (push a):** Move the first element from stack B to stack A.
- **`pb` (push b):** Move the first element from stack A to stack B.
- **`ra` (rotate a):** Rotate all elements of stack A up by one.
- **`rb` (rotate b):** Rotate all elements of stack B up by one.
- **`rr`:** Perform `ra` and `rb` simultaneously.
- **`rra` (reverse rotate a):** Rotate all elements of stack A down by one.
- **`rrb` (reverse rotate b):** Rotate all elements of stack B down by one.
- **`rrr`:** Perform `rra` and `rrb` simultaneously.

The project is an excellent exercise in algorithm optimization and problem-solving within a constrained environment. By designing and implementing an efficient algorithm, you will deepen your understanding of sorting techniques, data structures, and performance optimization.
