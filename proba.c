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

unsigned long combinaisons(int n, int k)
{
    //  n! / k!(n-k)!
    
    if (k < 0 || n < k)
        return 0;
        
    
    mpz_t a, b, c;
    
    
    mpz_init_set_str(a, big_factorial(n), 10);
    mpz_init_set_str(b, big_factorial(k), 10);
    mpz_init_set_str(c, big_factorial(n-k), 10);
    
    mpz_mul(b, b, c);
    
    mpz_div(a, a, b);
            
    return mpz_get_ui(a);
}