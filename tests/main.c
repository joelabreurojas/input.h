#include <stdio.h>

#include "input.h"

int main(void)
{
    char c = get_char("Char: ");
    char *s = get_string("String: ");
    double d = get_double("Double: ");
    float f = get_float("Float: ");
    int i = get_int("Int: ");
    long l = get_long("Long: ");

    putchar('\n');

    printf("c --> %c\n", c);
    printf("s --> %s\n", s);
    printf("d --> %lg\n", d);
    printf("f --> %g\n", f);
    printf("i --> %i\n", i);
    printf("l --> %li\n", l);

    return 0;
}
