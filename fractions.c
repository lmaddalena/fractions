#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
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
    
    assert(den != 0);
    
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
    //fraction_reduce(&f);
    
    return f;
}

//
// crea una frazione da un double
//
t_fraction fraction_fromdouble(double d) {
    
    int num;
    int den;
       
    if(!fraction_isdecimal(d))
    {
        num = (d > INT_MAX) ? INT_MAX : d;
        den = 1;
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
    
        num = (d > INT_MAX) ? INT_MAX : d;
        den = m;
        
    }
    
    // crea la frazione
    t_fraction f = fraction_create(num, den);

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

    assert(f->denominator != 0);

    int gcd = fraction_gcd(f->numerator, f->denominator);
    
    f->numerator = f->numerator / gcd;
    f->denominator = f->denominator / gcd;
}

//
// restituisce la frazione in formato string n/d
//
char *fraction_tostring(t_fraction f) {
    
    int fraction_digitcount(int);
    
    int i = 0;
    char *c = NULL;
    
    if(f.denominator == 1)
    {
        // conta le cifre
        i = fraction_digitcount(f.numerator);
   
        // cifre + \0      
        c = (char *)malloc(i + 1);
        sprintf(c, "%i", f.numerator);
        
    }
    else
    {
        // conta le cifre
        i = fraction_digitcount(f.numerator);
        i = i + fraction_digitcount(f.denominator);
    
        // cifre + sep + \0      
        c = (char *)malloc(i + 1 + 1);
        sprintf(c, "%i/%i", f.numerator, f.denominator);        
    }
    
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

//
// verifica che la stringa di input sia un numero
// 
int fraction_isnumeric(char *s) {
    
    if(*s == '-' || *s == '+')
        s++;
         
     if(*s == '\0')
        return 0;

    char c = *s;
    
    if(c == '\0')
        return 0;
    
    
    while((c = *s++) != '\0')
    {
        if(isdigit(c) == 0)
            return 0;        
    }
 
    return 1;
 
}

// 
// Crea una frazione da una string
//
t_fraction fraction_parse(char *s) {
    
    char *p;
    int idx = -1;
    int num = 1;
    int den = 1;
        
	// cerca il simbolo '/'
	p = (char *)strchr(s, '/');

	// calcola l'indice del simbolo '/'
	if (p != NULL)
		idx = p - s;
   
    if(idx == -1)
    {

        if(fraction_isnumeric(s))                
            num = atoi(s);
    }        
    else
    {
		char buff[10];
        
        // numeratore 
		strncpy(buff, s, idx);
		buff[idx] = '\0';
        if(fraction_isnumeric(buff))
		  num = atoi(buff);
            
        // denominatore
        strcpy(buff, s+idx+1);
        if(fraction_isnumeric(buff))
		  den = atoi(buff);        
    }
    
    t_fraction f =  fraction_create(num, den);
    return f;
}

//
// somma le frazioni f1 e f2
//
t_fraction fraction_sum(t_fraction f1, t_fraction f2) {

    assert(f1.denominator != 0);
    assert(f2.denominator != 0);
    
    int lcm = fraction_lcm(f1.denominator, f2.denominator);    
    int num = (f1.numerator * lcm / f1.denominator) + (f2.numerator * lcm / f2.denominator);   
    
    t_fraction f = fraction_create(num, lcm);
    fraction_reduce(&f);
    return f;
    
}

//
// sottrae le frazioni f1 e f2
//
t_fraction fraction_sub(t_fraction f1, t_fraction f2) {

    assert(f1.denominator != 0);
    assert(f2.denominator != 0);

    int lcm = fraction_lcm(f1.denominator, f2.denominator);    
    int num = (f1.numerator * lcm / f1.denominator) - (f2.numerator * lcm / f2.denominator);   
    
    t_fraction f = fraction_create(num, lcm);
    fraction_reduce(&f);
    return f;
    
}

//
// moltiplica le frazioni f1 e f2
// 
t_fraction fraction_mul(t_fraction f1, t_fraction f2) {
  
    t_fraction f = fraction_create(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
    fraction_reduce(&f);
    return f;
    
}

//
// divide la frazione f1 per la frazione f2
// 
t_fraction fraction_div(t_fraction f1, t_fraction f2) {
  
    t_fraction f = fraction_create(f1.numerator * f2.denominator, f1.denominator * f2.numerator);
    fraction_reduce(&f);
    return f;
    
}
