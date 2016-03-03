#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "fractions.h"

//
// converte una frazione in double
//
double fraction_todouble(t_fraction f) {
    
    return (double)f.numerator / (double)f.denominator;
}


//
// crea una nuova frazione
//
t_fraction fraction_create(int num, int den) {
    
    t_fraction f;
    
    // fa in modo che il segno sia al numeratore
    if(den < 0)
    {
        num = num * -1;
        den = den * -1;
    }
    f.numerator = num;
    f.denominator = den;
    
    // riduce ai minimi termini
    fraction_reduce(&f);
    
    return f;
}

//
// crea una frazione da un double
//
t_fraction fraction_fromdouble(double d) {
    
    t_fraction f;
    
    if(!fraction_isdecimal(d))
    {
        f.numerator = (d > INT_MAX) ? INT_MAX : d;
        f.denominator = 1;
    }
    else
    {
        int max = 9;
        int m = 1;
       
        while(fraction_isdecimal(d) && max > 0)
        {
            --max;
            m *= 10;
            d = d * 10.0;
        }
    
        f.numerator = (d > INT_MAX) ? INT_MAX : d;
        f.denominator = m;
        
    }
    
    // riduce ai minimi termini
    fraction_reduce(&f);
    
    return f;       
};

//
// ritorna 1 se il numero è decimale, altrimenti 0
// 
int fraction_isdecimal(double d) {

    if(d != floor(d))
        return 1;
    else
        return 0;
    
}

//
// restituisce il minimo comune multiplo di m e n
//
int fraction_lcm(int m, int n) {
    
    int lcm = abs(m * n) / fraction_gcd(m, n);
    return lcm;
}

//
// restitiuisce il massimo comun divisore tra m e n
//
int fraction_gcd(int m, int n) {
       
    // swap
    if( n > m)
    {
        int t = m;
        m = n;
        n = t;
    }
       
   int r;

    while(1)
    {
        r = m % n;
        if(r == 0)
        {
            return abs(n);            
        }
        else
        {
            m = n;
            n = r;
        }        
    }            
}

//
// riduce la frazione ai minimi termini
//
void fraction_reduce(t_fraction *f) {

    int gcd = fraction_gcd(f->numerator, f->denominator);
    
    f->numerator = f->numerator / gcd;
    f->denominator = f->denominator / gcd;
}

//
// restituisce la frazione in formato string n/d
//
char *fraction_tostring(t_fraction f) {
    
    int fraction_digitcount(int);
    
    int i = fraction_digitcount(f.numerator);
    i = i + fraction_digitcount(f.denominator);
  
    // cifre + sep + \0      
    char *c = (char *)malloc(i + 1 + 1);
    sprintf(c, "%i/%i", f.numerator, f.denominator);
    
    return c;
}

//
// conta il numero di cifre che ha il numero compreso il segno (lo zero conta)
//
int fraction_digitcount(int a) {
    
    int i = 0;
    
    if(a < 0)
        i++;
    do
    {
        a /= 10;
        i++;
    } while (a != 0);
    
    return i;
    
}