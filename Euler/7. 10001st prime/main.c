#include <stdio.h>
#include <stdlib.h>

int eshtNumerPrim(long long numri){
    long long i;
    for(i = 2; i * i <= numri; i++){
        if(numri % i == 0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i = 2, sasia = 0;
    while(sasia != 10001 ){
        if(eshtNumerPrim(i)){
            sasia++;
            printf("%d sasia: %d\n",i, sasia);
        }
        i++;
    }
    return 0;
}
