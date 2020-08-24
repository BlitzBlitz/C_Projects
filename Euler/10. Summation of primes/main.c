#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Summation of primes
Problem 10
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

int eshtNumerPrim(long numri){
    long long i;
    for(i = 2; i <= sqrt(numri); i++){
        if(numri % i == 0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i = 2;
    long long shuma = 0;
    while (i < 2000000){
        if(eshtNumerPrim(i)){
            shuma += i;
        }
        i++;
    }
    printf("%lld", shuma);
    return 0;
}
