<h1 align='center'>
    input.h
    <br>
    <a href="https://github.com/j4breu/input.h/blob/main/LICENSE">
    <img
        alt='Logo'
        src='https://img.shields.io/static/v1.svg?style=for-the-badge&label=License&message=MIT&logoColor=d9e0ee&colorA=302d41&colorB=555555'/>
    </a>
    <div></div>
</h1>

<p align='center'>
    <em>Library that uses heap to simplify user input in C.</em>
</p>

&nbsp;

### ✨ Overview

This is a C library, inspired by [libcs50](https://github.com/cs50/libcs50), that simplifies the process of getting user input. It provides a convenient way to display a message, read user input, filter it and return it if valid. If the input is invalid, the library repeats the process until valid input is received.

The main goal is to understand memory management with the heap as it is built, and to provide a higher level abstraction for handling user input. Contributions and suggestions are welcome to further improve and extend the functionality.

&nbsp;

### 🔧 Set up

1. Clone the repository.
2. Link the path when you want execute your program.

&nbsp;

### 💻 Usage

```
#include "input.h"

// The syntax is similar to <type> input = get_<type>("message");
// And type can be char, string (char *), double, float, integer and long

...

// Normal
char name = get_char("Message");

// Format
char name = get_char("%s", message);

// String case
char *name = get_string("Message");
char *name = get_string("%s", message);

...
```

&nbsp;

### 👐 Contribute

> Improvements?

* Don't hesitate to create a PR.

> Problems?

* Feel free to open a new issue!

&nbsp;

### 🔎 See more

* [Dynamic String with Memory Allocation](https://stackoverflow.com/questions/62878982/how-to-make-a-dynamic-string)
* [Comparison between getchar/putchar, gets/puts and fgets/fputs](https://stackoverflow.com/questions/39224580/what-is-the-difference-between-getchar-putchar-gets-puts-and-fgets-fputs-in-c)
* [Comparison between atoi, atol, strtol, stroul and sscanf](https://stackoverflow.com/questions/22865622/atoi-vs-atol-vs-strtol-vs-strtoul-vs-sscanf)
* [Correct use of strol](https://stackoverflow.com/questions/14176123/correct-usage-of-strtol/14176593#14176593)
* [Equivalent `__attribute__((constructor))` for VC](https://gist.github.com/tenmyo/dde01e838cdaf14c8353fbad03ab9bc8)
* [Read line by line](https://stackoverflow.com/questions/3501338/c-read-file-line-by-line)
* [Variatic arguments](https://stackoverflow.com/questions/3530771/passing-variable-arguments-to-another-function-that-accepts-a-variable-argument)

