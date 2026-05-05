*This project has been created as part of the 42 curriculum by mapatenk.*

## Description
**Push_swap** is a sorting algorithm project that requires sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, one must manipulate various types of algorithms and choose the most appropriate solution for optimized data sorting. 

The goal of this project is to sort a list of integers given as arguments into "Stack A" in ascending order, utilizing a secondary "Stack B" as an intermediary, all while minimizing the total number of operations.

## Instructions
### Compilation
The project includes a Makefile providing the following standard rules:
- `make` or `make all` - Compiles the project and generates the `push_swap` executable.
- `make clean` - Removes object files.
- `make fclean` - Removes object files and the executable.
- `make re` - Recompiles both the libft and the push_swap executable from scratch.

### Execution
Run the program by passing a randomly formatted list of integers:
```bash
./push_swap 4 67 3 87 23
```
The program will output the sequence of operations (e.g., `sa`, `pb`, `ra`) required to sort the stack.

## Resources
- [42 Push_swap Guide](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Radix Sort Algorithm explanation](https://en.wikipedia.org/wiki/Radix_sort)
- **AI Usage:** AI was used primarily for debugging edge cases, creating this README template according to 42 curriculum requirements, and helping structure the bitwise operations in the Radix Sort mechanism.

## Algorithm and Data Structure Justification

### Data Structure
Rather than relying on classic Linked Lists which require constant dynamic allocation tracking, this implementation opts for **dynamically allocated arrays** (`int *a` and `int *b`) to simulate the stacks. Accompanying integer variables (`size_a` and `size_b`) track the bounds of these pseudo-stacks. Arrays are highly advantageous here as they offer $O(1)$ random access speeds necessary for the coordinate compression parsing, resulting in better CPU spatial locality and overall faster execution.

### Algorithm
The project implements a two-fold algorithmic approach to optimally reduce operation count across different input sizes:

1. **Normalization (Coordinate Compression):** Before sorting begins, the input array is parsed and reduced to ranked indices (e.g., the smallest exact value becomes `0`, the largest becomes `N - 1`). This establishes bounded contiguous values and removes negative numbers, an absolute necessity for efficient bitwise arithmetic.
2. **Small Sets (Hardcoded sorting):** For $N \le 5$, the overhead of mathematical sorting is too high. Specific functions (`sort3`, `sort4`, `sort5`) apply a mathematically proven sequence of lowest operations to handle the small combinations efficiently without recursion.
3. **Large Sets (Bitwise Radix Sort):** For large sets (100 and 500 numbers), the algorithm uses a **Base-2 Radix Sort**. Iterating bit-by-bit from the least significant bit (LSB) to the most significant bit (MSB), the algorithm pushes numbers with a `0` at the current bit to `Stack B` (`pb`) and rotates numbers with a `1`  (`ra`). Once a bit column is fully evaluated, numbers are pushed back to `Stack A` (`pa`). Because values are 0-indexed and normalized, the Radix Sort guarantees a completely sorted stack in almost exactly $O(N \cdot K)$ operations, where $K$ is the number of bits required to represent the largest integer.