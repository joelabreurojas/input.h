<h1 align='center'>
    hinput
</h1>

<p align='center'>
    <em>Heap-based input() with type validation — a C library for safe, dynamic user input.</em>
</p>

<h6 align='center'>
    <a href="https://github.com/joelabreurojas/hinput/blob/main/LICENSE">
        <img alt='MIT License' src='https://img.shields.io/static/v1.svg?label=License&message=MIT&logoColor=d9e0ee&colorA=302d41&colorB=3094FF'/>
    </a>
</h6>

&nbsp;

### ✨ Overview

Lightweight C library that provides safe, type-validated user input functions. It replaces the standard `getchar()`, `gets()`, `scanf()` family with robust alternatives that handle memory management and input validation automatically.

**Why hinput?**

- **Heap-allocated buffers**: Dynamic sizing via `malloc`/`realloc`, no fixed limits
- **Automatic cleanup**: Memory freed via `__attribute__((destructor))`
- **Type validation**: Input is validated against expected types (int, float, string, etc.)
- **Variadic format strings**: Printf-style prompt formatting
- **Cross-platform**: Works with GCC on Linux/macOS

&nbsp;

### 🚀 Getting Started

#### Prerequisites

- GCC compiler (or compatible C11 compiler)
- Make (optional, for building with Makefile)

#### Installation

Clone the repository:

```bash
git clone https://github.com/joelabreurojas/hinput.git
cd hinput
```

Build using Make:

```bash
make all
```

Or compile manually:

```bash
gcc -Wall -Wextra -pedantic -std=c11 -c src/input.c -o build/input.o
```

&nbsp;

### 📖 Usage

Include the header in your project:

```c
#include "hinput.h"

int main(void)
{
    char c = get_char("Enter a character: ");
    char *s = get_string("Enter a string: ");
    int i = get_int("Enter an integer: ");
    float f = get_float("Enter a float: ");

    printf("You entered: %c, %s, %i, %g\n", c, s, i, f);

    return 0;
}
```

Compile with the library:

```bash
gcc your_program.c build/input.o -o your_program -lm
```

&nbsp;

### 🔧 API Reference

| Function | Return Type | Description |
|----------|-------------|-------------|
| `get_char(format, ...)` | `char` | Reads a single character |
| `get_string(format, ...)` | `char*` | Reads a string (caller must free) |
| `get_int(format, ...)` | `int` | Reads an integer |
| `get_long(format, ...)` | `long` | Reads a long integer |
| `get_float(format, ...)` | `float` | Reads a float |
| `get_double(format, ...)` | `double` | Reads a double |

All functions accept a printf-style format string for the prompt.

&nbsp;

### 🧪 Testing

Run the interactive test suite:

```bash
echo "test" | make test
```

&nbsp;

### 📄 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.
