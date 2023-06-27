#include <limits.h>
#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int a;
    char *s;

    a = 5056;
    s = tostring(a);
    printf("str %s\n", s);
    _printf("str %s\n", s);
    printf("int %i, %d\n", a, a);
    _printf("int %i, %d\n", a, a);
    free(s);

    return (0);
}
