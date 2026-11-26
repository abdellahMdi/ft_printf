*This project has been created as part of the 42 curriculum by abdemahm.*

# ft_printf

## Description

**ft_printf** is a C programming project from the 42 curriculum whose goal is to recode the standard C library function `printf()`. The library produces formatted output to the standard output (`stdout`) and returns the total number of characters printed (or `-1` if an output error occurs).

This project introduces **variadic functions** in C (`<stdarg.h>`), low-level output handling via the `write()` system call, and modular library design. Once compiled, `libftprintf.a` can be integrated into future 42 C projects as a custom, norm-compliant replacement for `printf()`.

### Supported Conversion Specifiers

| Specifier | Description |
| :--- | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a null-terminated string. |
| `%p` | Prints a `void *` pointer argument in hexadecimal format prefixed with `0x` (prints `(nil)` for `NULL`). |
| `%d` | Prints a signed decimal (base 10) number. |
| `%i` | Prints a signed integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in lowercase hexadecimal (base 16). |
| `%X` | Prints a number in uppercase hexadecimal (base 16). |
| `%%` | Prints a literal percent sign (`%`). |

---

## Instructions

### Prerequisites

- A C compiler (`cc`, `gcc`, or `clang`)
- `make`

### Compilation

Clone the repository and run `make` at the root of the project to compile the static library `libftprintf.a`:

```bash
make
```

#### Available Makefile Rules

- `make` / `make all` — Compiles the source files and archives them into `libftprintf.a`.
- `make clean` — Removes all generated object files (`.o`).
- `make fclean` — Removes all object files and the compiled library (`libftprintf.a`).
- `make re` — Performs a full clean rebuild (`fclean` followed by `all`).

### Usage

Include the header `ft_printf.h` in your C source file and link `libftprintf.a` during compilation:

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    int value = 42;

    count = ft_printf("Hello %s! Value: %d | Hex: %x | Ptr: %p | 100%%\n",
                      "42", value, value, &value);
    ft_printf("Total characters printed: %d\n", count);
    return (0);
}
```

Compile your program with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf
```

---

## Algorithm and Data Structure

### Algorithm: Single-Pass Linear Parser with Dispatcher

The core of `ft_printf` is built around a **single-pass linear scan** over the format string combined with a **modular dispatcher pattern**:

1. **Format String Traversal (`ft_print_inputs`)**:
   - The format string is iterated character by character from index `0` to the null terminator (`'\0'`), running in $O(n)$ time complexity where $n$ is the length of the format string.
   - Regular characters are written directly to `stdout`.
   - When a `%` character is encountered, the following character is validated with `check_type()`. If it matches a supported specifier, execution is delegated to `ft_handler()`.
2. **Conversion Dispatch (`ft_handler`)**:
   - Extracts the next argument from the `va_list` with the appropriate promoted type (e.g., `int` for `%c`, `unsigned int` for `%x`/`%X`, `void *` for `%p`) and calls the dedicated formatting helper.
   - Accumulates the number of bytes written and immediately propagates `-1` if any `write()` or allocation error occurs.
3. **Base Conversion (Decimal & Hexadecimal)**:
   - For numeric conversions (`ft_printf_num.c` and `ft_printf_hex.c`), the exact number of digits is first calculated recursively in $O(\log_b |k|)$ time (where $b = 10$ for decimals and $b = 16$ for hexadecimals).
   - Digits are then extracted iteratively from least significant to most significant using modulo and division, filling the buffer from right to left. This eliminates the need for a second pass to reverse the string.
   - Signed integers are cast to `long` (and unsigned integers to `unsigned long`) before conversion so edge cases such as `INT_MIN` ($-2147483648$) can be negated safely without signed integer overflow.
4. **Pointer Formatting (`ft_printf_voidp.c`)**:
   - Checks for `NULL` first and outputs `"(nil)"` directly.
   - Otherwise, casts the address to `unsigned long`, writes the `"0x"` prefix, and delegates the address value to the lowercase hexadecimal formatter.

### Data Structures and Justification

- **`va_list` (Variadic Argument List)**:
  - Used to sequentially access an arbitrary number of typed arguments passed to `ft_printf`. It is the standard, portable C mechanism for variadic functions and requires no custom heap-allocated argument container.
- **Dynamically Allocated String Buffers (`char *`) for Numeric Conversions**:
  - Rather than calling `write()` once per digit, `ft_itoa()`, `ft_itoau()`, and `ft_printf_hex()` allocate a right-sized `char *` buffer (`len + 1` bytes), populate all characters, emit the full number in a **single `write()` system call**, and immediately `free()` the buffer.
  - *Justification*: Minimizes expensive kernel system calls while keeping memory footprint tiny and strictly scoped to each conversion.
- **Static Lookup Tables (`"0123456789abcdef"` / `"0123456789ABCDEF"`)**:
  - Hexadecimal digits are mapped via direct array indexing (`hex[n % 16]`), providing $O(1)$ digit-to-character conversion with clean, branch-free logic.

### Project Structure

- `ft_printf.h` — Public header declaring `ft_printf` and required standard includes.
- `ft_printf.c` — Entry point, format string parser, and conversion dispatcher.
- `ft_printf_char.c` — Character (`%c`), string (`%s`), and string length utilities.
- `ft_printf_num.c` and `ft_printf_num2.c` — Signed (`%d`, `%i`) and unsigned (`%u`) integer conversion and output.
- `ft_printf_hex.c` — Lowercase (`%x`) and uppercase (`%X`) hexadecimal conversion and output.
- `ft_printf_voidp.c` — Pointer (`%p`) formatting and `NULL` handling.

---

## Resources

### References

- **Linux Programmer's Manual**:
  - `man 3 printf` — Specification and behavior of the standard `printf()` function.
  - `man 3 stdarg` — Documentation for variadic function macros (`va_start`, `va_arg`, `va_end`).
  - `man 2 write` — Low-level file descriptor output and error handling.
- **C Reference Documentation**:
  - [cppreference — Variadic functions](https://en.cppreference.com/w/c/variadic)
  - [cppreference — printf, fprintf, sprintf](https://en.cppreference.com/w/c/io/fprintf)
- **42 Curriculum**:
  - Official 42 `ft_printf` project subject.

### Use of AI

AI (Gemini) was used during this project specifically for **documentation**:
- Drafting and structuring this `README.md` file to meet all 42 curriculum formatting requirements.
- Summarizing the project's modular architecture, algorithm, and data structure choices based on the implemented C source files.

All C source code, logic design, and debugging were authored and verified by `abdemahm`.