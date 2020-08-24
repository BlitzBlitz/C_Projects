#include <stdio.h>
#include <stdlib.h>
/*
Smallest multiple
Problem 5
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
long long faktoriali(int numri){    // gjejme shumfishim me te madhe te perbashket
    if(numri == 1){
        return 1;
    }
    return numri * faktoriali(numri - 1);
}

int plotpjestohetMeTeGjithe(long long numri, int numri1){  // provojme te pjestojme me te gjithe numrat nese plotpjestohet eshte shumfish
    while(numri1 > 0){
        if(numri % numri1 != 0){
            return 0;
        }
        numri1--;
    }
    return 1;
}

long long pjestuesiMeIvogel(int numriNga1deriNe){
    long long SHMP; // shumfishi me i madh i perbashket
    SHMP = faktoriali(numriNga1deriNe);
    int i;
    for(i = numriNga1deriNe; i > 0; i--){
        if(plotpjestohetMeTeGjithe(SHMP / i, numriNga1deriNe)){     // ShMP e pjestojme me secilin numer dhe per numrin q del nga ky
            SHMP /= i;                                              // pjestim  kontrollojme nese eshte shumfish per te gjith numrat
        }                                                           // e tjere
    }
    return SHMP;
}

int main()
{
    printf("\n%lld",pjestuesiMeIvogel(20));
    return 0;
}
