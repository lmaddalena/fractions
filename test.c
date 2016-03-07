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
    
    t_fraction f = fraction_create(12981,-231);
    t_fraction f1 = fraction_fromdouble(-.125);
    t_fraction f2 = fraction_create(3,2);
    t_fraction f3 = fraction_parse("-2/3");          
    
    printf("%s = %10.9f \n", fraction_tostring(f), fraction_todouble(f));
    printf("%s = %10.9f \n", fraction_tostring(f1), fraction_todouble(f1));          
    printf("%s = %10.9f \n", fraction_tostring(f2), fraction_todouble(f2));
    printf("%s = %10.9f \n", fraction_tostring(f3), fraction_todouble(f3));


    printf("%s + %s = %s \n", fraction_tostring(f2), fraction_tostring(f3),fraction_tostring(fraction_sum(f2, f3)));
    printf("%s - %s = %s \n", fraction_tostring(f2), fraction_tostring(f3),fraction_tostring(fraction_sub(f2, f3)));
    printf("%s * %s = %s \n", fraction_tostring(f2), fraction_tostring(f3),fraction_tostring(fraction_mul(f2, f3)));
    printf("%s : %s = %s \n", fraction_tostring(f2), fraction_tostring(f3),fraction_tostring(fraction_div(f2, f3)));
    
    printf("%s + %s + %s = %s \n", fraction_tostring(f1), fraction_tostring(f2), fraction_tostring(f3),fraction_tostring(
        fraction_sum( fraction_sum(f2, f3), f1 )
            ));
                 
    //mdump(stdout, &f, sizeof(t_fraction));
    return 0;
}