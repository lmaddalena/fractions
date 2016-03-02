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
t_fraction fraction_fromint(int i);
int fraction_isdecimal(double);
#endif