#include <math.h>
#include <float.h>
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
        f.numerator = (int)d;
        f.denominator = 1;
    }
    else
    {
        int max = 10;
        int m = 1;
       
        while(fraction_isdecimal(d) && max > 0)
        {
            max--;
            m *= 10;
            d = d * 10.0;
            
            //printf("m=%i d=%f (int)d=%i\n", m, d, (int)d);
        }
        
        f.numerator = d;
        f.denominator = m;
        
    }
    
    return f;
    
        
        
};



//
// crea una funzione da un int
//

t_fraction fraction_fromint(int i) {
    
};

//
// ritorna 1 se il numero è decimale, altrimenti 0
// 
int fraction_isdecimal(double d) {
    
    if((int)d == d)
        return 0;
    else
        return 1;
    /*  
        
    int s = 1;
    
    if(d < 0) 
        s = -1;
    
    int i = fabs(d) * s;

    double f = d - i;
    printf("@@%Lf\n", f);
    
    if(f != 0.0)
        return 1;
    else
        return 0;
    */  
}