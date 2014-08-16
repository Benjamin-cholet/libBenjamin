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
    
    //printf("n! : %s\nk! : %s\n(n-k)! : %s\n", big_factorial(n), big_factorial(k), big_factorial(n-k));

    mpz_mul(b, b, c);
    
    //printf("k!(n-k)! : %ld\n", mpz_get_ui(b));
    
    mpz_div(a, a, b);
    
    //printf("n! / (k!(n-k)!) : %ld\n", mpz_get_ui(a));
        
    return mpz_get_ui(a);
}