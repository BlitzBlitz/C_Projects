#include <stdio.h>
#include <stdlib.h>

int kerkoRekursiv(int x, int v[], int n){
    if(n <= 0){
        return 0;
    }
    if(x == v[n - 1]){
        return 1;
    }
    return kerkoRekursiv(x, v, n - 1);
}

int main()
{
    int v[5] = {1, 2, 33, -44, 3};
    printf("%d", kerkoRekursiv(3, v, 5));
    return 0;
}

