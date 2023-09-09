#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "input.h"

#if defined (__GNUC__)
    static void __attribute__((destructor)) cleanup(void);
#else
    #error Default compiler / version is not recognized.
#endif

char *str = NULL;

static void cleanup(void)
{
    free(str);
}

static int endofline(int c)
{
    int eol = (c == '\r' || c == '\n');

    if (c == '\r' && (c = fgetc(stdin)) != '\n' && c != EOF)
    {
        if (ungetc(c, stdin) == EOF)
        {
            return -1;
        }
    }

    return eol;
}

char get_char(const char *message)
{
    char c, i, *input = NULL;

    do
    {
        if (!(input = get_string(message)))
        {
            return CHAR_MAX;
        }
    }
    while (sscanf(input, "%c%c", &c, &i) != 1);

    return c;
}

double get_double(const char *message)
{
    char c, *input = NULL;
    double d = 0;

    do
    {
        if (!(input = get_string(message)))
        {
            return DBL_MAX;
        }
    }
    while (sscanf(input, "%lg%c", &d, &c) != 1);

    return d;
}

float get_float(const char *message)
{
    char c, *input = NULL;
    float f = 0;

    do
    {
        if (!(input = get_string(message)))
        {
            return FLT_MAX;
        }
    }
    while (sscanf(input, "%g%c", &f, &c) != 1);

    return f;
}

int get_int(const char *message)
{
    char c, *input = NULL;
    int i = 0;

    do
    {
        if (!(input = get_string(message)))
        {
            return INT_MAX;
        }
    }
    while (sscanf(input, "%i%c", &i, &c) != 1);

    return i;
}

long get_long(const char *message)
{
    char c, *input = NULL;
    long l = 0;

    do
    {
        if (!(input = get_string(message)))
        {
            return LONG_MAX;
        }

    }
    while (sscanf(input, "%li%c", &l, &c) != 1);

    return l;
}

char *get_string(const char *message)
{
    char *aux = NULL;
    int c = 0, eol = 0;
    size_t len = 0;

    printf("%s", message);

    if (!(str = malloc(1)))
    {
        return NULL;
    }

    while ((c = fgetc(stdin)) != EOF && !(eol = endofline(c)))
    {
        if (eol == -1 || len + 1 > SIZE_MAX)
        {
            return NULL;
        }

        str[len++] = (char)c;

        if (!(aux = realloc(str, len)))
        {
            return NULL;
        }
        str = aux;
    }

    str[len] = '\0';

    return str;
}
