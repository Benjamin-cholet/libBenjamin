//
//  libBenjamin.c
//  libBenjamin
//
//  Created by Benjamin on 13/07/2014.
//
//

#include "libBenjamin.h"
#include <gmp.h>
#include <stdio.h>
#include <limits.h>

unsigned long factorial(int a)
{
    if (a <= 1)
        return 1;
    
    unsigned long fact = 1;
    
    while (a > 0) {
        fact *= a;
        
        if (ULONG_MAX / a < fact) {
            printf("Factorial is too big !!");
            return -1;
        }
        a--;
    }
    return fact;
}

char *big_factorial(int a)
{
    if (a <= 1)
        return "1";
    
    mpz_t p;
    
    mpz_init_set_ui(p,1);
    for (int i=1; i <= a ; ++i){
        mpz_mul_ui(p,p,i);
    }
    
    //    mpz_clear(p);
    
    
    return mpz_get_str(NULL, 10, p);
}