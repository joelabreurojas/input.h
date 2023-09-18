# input.h

This is a C library, inspired by [libcs50](https://github.com/cs50/libcs50), that simplifies the process of getting user input. It provides a convenient way to display a message, read user input, filter it and return it if valid. If the input is invalid, the library repeats the process until valid input is received.

The main goal is to understand memory management with the heap as it is built, and to provide a higher level abstraction for handling user input. Contributions and suggestions are welcome to further improve and extend the functionality.

## Installation

1. Clone the repository.
2. Link the path when you want execute your program.

## Usage

```c
#include <stdio.h>.
#include "input.h"

// The syntax is similar to
// <type> input = get_<type>("message");
// And type can be char, char*(string), double, float, integer and long.

int main()
{
    char *name = get_string("Enter your name: ")
    printf("Hello, %s!\n", name)

    return 0;
}
```

## Additional resources

* [Dynamic String with Memory Allocation](https://stackoverflow.com/questions/62878982/how-to-make-a-dynamic-string)
* [Comparison between getchar/putchar, gets/puts and fgets/fputs](https://stackoverflow.com/questions/39224580/what-is-the-difference-between-getchar-putchar-gets-puts-and-fgets-fputs-in-c)
* [Comparison between atoi, atol, strtol, stroul and sscanf](https://stackoverflow.com/questions/22865622/atoi-vs-atol-vs-strtol-vs-strtoul-vs-sscanf)
* [Correct use of strol](https://stackoverflow.com/questions/14176123/correct-usage-of-strtol/14176593#14176593)
* [Equivalent `__attribute__((constructor))` for VC](https://gist.github.com/tenmyo/dde01e838cdaf14c8353fbad03ab9bc8)
* [Read line by line](https://stackoverflow.com/questions/3501338/c-read-file-line-by-line)
