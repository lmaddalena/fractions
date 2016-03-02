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
    f.numerator = num;
    f.denominator = den;
    return f;
}

//
// crea una funzione da un double
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