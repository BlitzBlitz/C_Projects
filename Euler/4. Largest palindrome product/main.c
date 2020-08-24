#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Largest palindrome product
Problem 4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

int eshteNumriPalindrom(int numri){
    int numriParc = numri, numriMbrapsht = 0;
    while(numri != 0){
        numriMbrapsht = numriMbrapsht * 10 + numri % 10;
        numri /= 10;
    }
    if(numriParc == numriMbrapsht){
        return 1;
    }
    return 0;
}
int sasiaShifrave(int numri){
    int sasia = 0;
    while(numri != 0){
        numri /= 10;
        sasia++;
    }
    return sasia;
}

int palindromaMeEmadheMe6shifra(int *numri1){
    int i, j;
    for(i = 998001; i > 100000; i--){
        if(eshteNumriPalindrom(i)){

            for(j = 999; j > 100; j--){
                if((i % j == 0)&&( sasiaShifrave(i / j) == 3)){
                    printf("%d = %d * %d\n",i, j, i / j);
                    return i;
                }
            }

        }
    }
    return -1;
}

int main()
{
    int n;
    printf("%d", palindromaMeEmadheMe6shifra(&n));
    return 0;
}
