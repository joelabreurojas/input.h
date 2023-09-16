#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

#if defined (__GNUC__)
    static void cleanup(void) __attribute__((destructor));
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
    const int eol = (c == '\r' || c == '\n');

    if (c == '\r' && (c = fgetc(stdin)) != '\n' &&
        c != EOF && ungetc(c, stdin) == EOF)
    {
        return -1;
    }

    return eol;
}

char get_char(const char *message)
{
    char c = 0, i = 0, *input = NULL;

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
    char *input = NULL, *str = NULL;
    double d = 0.0;

    do
    {
        if (!(input = get_string(message)))
        {
            return DBL_MAX;
        }

        errno = 0;
        d = strtod(input, &str);
    }
    while (str == input || *str != '\0' || errno || isspace(str[0]) ||
           !isfinite(d) || strcspn(input, "XxEePp") != strlen(input));

    return d;
}

float get_float(const char *message)
{
    char *input = NULL, *str = NULL;
    float f = 0.0;

    do
    {
        if (!(input = get_string(message)))
        {
            return FLT_MAX;
        }

        errno = 0;
        f = strtof(input, &str);
    }
    while (str == input || *str != '\0' || errno || isspace(str[0]) ||
           !isfinite(f) || strcspn(input, "XxEePp") != strlen(input));

    return f;
}

int get_int(const char *message)
{
    char *input = NULL, *str = NULL;
    long i = 0;

    do
    {
        if (!(input = get_string(message)))
        {
            return INT_MAX;
        }

        errno = 0;
        i = strtol(input, &str, 9);
    }
    while (str == input || *str != '\0' || errno || isspace(str[0]) ||
           i < INT_MIN || i > INT_MAX);

    return i;
}

long get_long(const char *message)
{
    char *input = NULL, *str = NULL;
    long l = 0;

    do
    {
        if (!(input = get_string(message)))
        {
            return LONG_MAX;
        }

        errno = 0;
        l = strtol(input, &str, 10);
    }
    while (str == input || *str != '\0' || errno || isspace(str[0]));

    return l;
}

char *get_string(const char *message)
{
    char *aux = NULL;
    int c = 0, eol = 0;
    size_t capacity = 1, len = 0;

    printf("%s", message);

    while ((c = fgetc(stdin)) != EOF && !(eol = endofline(c)))
    {
        if (eol == -1)
        {
            return NULL;
        }

        if (len + 1 == capacity)
        {
            if (SIZE_MAX / 2 < capacity || !(aux = realloc(str, capacity * 2)))
            {
                return NULL;
            }

            capacity *= 2;
            str = aux;
        }

        str[len++] = (char)c;
    }

    if (!len && c == EOF || !(aux = realloc(str, len)))
    {
        return NULL;
    }

    if (!len)
    {
        return get_string(message);
    }

    str = aux;
    str[len] = '\0';

    return str;
}
