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
    int len,len2;
    char c;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");

    printf("**Length:[%d, %d]\n\n", len, len2);

    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');

    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");

    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    _printf("String:[%s] <%s>\n", "I am a string %%%", NULL);
    printf("String:[%s] <%s>\n", "I am a string %%%", NULL);

    len = _printf("String:[%s] <%s>\n", "I am a string %%%", NULL);
    len2 = printf("String:[%s] <%s>\n", "I am a string %%%", NULL);
    printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    len = _printf("");
    len2 = printf("");
    printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    printf("dec: %i %d\n", 10, 10);
    printf("oct: %i %d\n", 010, 010);
    printf("hex: %i %d\n", 0x10, 0x10);

    len = len - len + 0x10;
    printf(">>%d\n", len);
    write(1, &len, 1);
    printf("\n");
    write(1, &len, 4);
    _printf("\n");
    c = 'e';
    write(1, &c, 1);
    _printf("\n");

    return (0);
}
