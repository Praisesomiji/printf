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
    unsigned int u, v;

    u = 98;
    v = -98;
    printf("ub: %b, v: %d\n", u, v);
    _printf("ub: %b, v: %d\n", u, v);

    a = chbase(110, 2, 10);
    printf("binary D: %d\n", a);
    _printf("binary D: %d\n", a);

    a = chbase(6, 10, 2);
    printf("binary B: %d\n", a);
    _printf("binary B: %d\n", a);

    a = _topower(3, 3);
    printf("power27: %d\n", a);
    _printf("power27: %d\n", a);

    a = 5056;
    s = tostring(a);
    printf("str %s\n", s);
    _printf("str %s\n", s);
    printf("int %i, %d\n", a, a);
    _printf("int %i, %d\n", a, a);
    free(s);

    printf("NULL: %s\n", NULL);
    _printf("NULL: %s\n", NULL);

    return (0);
}
