#include <stdio.h>
#include <stdlib.h>

unsigned long int fibonachi(int n){
    unsigned long int k1 = 1, k2 = 1, k3 = 1;
    if(n <= 1){
        return k1;
    }
    if(n == 2){
        return k2;
    }
    while(n > 2){
        k3 = k1 + k2;
        k1 = k2;
        k2 = k3;
        n--;
    }
    return k3;
}

int main()
{
    printf("%ld", fibonachi(10));
    return 0;
}
