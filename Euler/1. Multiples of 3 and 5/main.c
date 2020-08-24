#include <stdio.h>
#include <stdlib.h>
/*
    If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
    Find the sum of all the multiples of 3 or 5 below 1000.
*/
int eshtePjestuesI3ose5(int numri){
    if((numri % 3 == 0)||(numri % 5 == 0)){
        return 1;
    }
    return 0;
}

int shumaEshumfishaveTe3dhe5(int sasia){
    int i, shuma = 0;
    for(i = 0; i < sasia; i++){
        if(eshtePjestuesI3ose5(i)){
            shuma += i;
        }
    }
    return shuma;
}
int main()
{
    printf("%d\n", shumaEshumfishaveTe3dhe5(1000));
    return 0;
}
