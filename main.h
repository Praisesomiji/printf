#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);

/* utils */
char *tostring(int num);
int chbase(int num, const int sbase, const int dbase);
int _topower(int b, int x);
int printstr(char *str);

#endif /* MAIN_H_ */
