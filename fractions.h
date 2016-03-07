#ifndef FRACTIONS_H
#define FRACTIONS_H

#include <stdlib.h>

struct fraction {
    int numerator;
    int denominator;
};

typedef struct fraction t_fraction;

double fraction_todouble(t_fraction);
t_fraction fraction_create(int num, int den);
t_fraction fraction_fromdouble(double d);
int fraction_isdecimal(double);
int fraction_gcd(int, int);
int fraction_lcm(int, int);
void fraction_reduce(t_fraction *);
char *fraction_tostring(t_fraction);
t_fraction fraction_parse(char *s);
int fraction_isnumeric(char *s);
t_fraction fraction_sum(t_fraction, t_fraction);
t_fraction fraction_sub(t_fraction, t_fraction);
t_fraction fraction_mul(t_fraction, t_fraction);
t_fraction fraction_div(t_fraction, t_fraction);
#endif