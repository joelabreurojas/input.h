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
    const int eol = (c == '\r' || c == '\n');

    if (c == '\r' && (c = getc(stdin)) != '\n' &&
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
    while (str == input || *str != '\0' || errno ||
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
    while (str == input || *str != '\0' || errno ||
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
    while (str == input || *str != '\0' || errno &&
           i >= INT_MIN && i <= INT_MAX);

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
    while (str == input || *str != '\0' || errno);

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

    while ((c = getc(stdin)) != EOF && !(eol = endofline(c)))
    {
        if (eol == -1 || len > SIZE_MAX - 1)
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

    if (!len && c == EOF)
    {
        return NULL;
    }

    if (!len || isspace(str[0]))
    {
        return get_string(message);
    }

    str[len] = '\0';

    return str;
}
