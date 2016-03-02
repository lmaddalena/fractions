#include <stdlib.h>
#include <stdio.h>
#include "fractions.h"

/* ********************************************************************************************
 *  indica al linker di eseguire la ricerca della libreria MDUMP.LIB durante il collegamento.  
 *  Il linker esegue la ricerca prima nella directory di lavoro, 
 *  quindi nel percorso specificato nella variabile di ambiente LIB.
 *  In alternativa compilare con l'opzione  /link dump.lib
 *********************************************************************************************/
#pragma comment(lib,"mdump.lib") //mdump Library


int main(int argc, char **argv)
{
    printf("Test fractions\n");
    printf("--------------\n");
    
    t_fraction f;
    //f = fraction_create(2,1);   
    //printf("%i\\%i = %f \n", f.numerator, f.denominator, fraction_todouble(f));          
    
    f = fraction_fromdouble(.125);
    printf("%i\\%i = %10.9f \n", f.numerator, f.denominator, fraction_todouble(f));
      
    
    //mdump(stdout, &f, sizeof(t_fraction));
    

    return 0;
}