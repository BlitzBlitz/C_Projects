#include <stdio.h>
#include <stdlib.h>

int sasiaRekursive(int x, int v[], int n){
    if(n <= 0){
        return 0;
    }
    return (v[n-1] == x ) + sasiaRekursive(x, v, n - 1);
}

int main()
{
    int v[5]= {101, 2, 2, 10, 11};
    printf("%d", sasiaRekursive(10, v, 5));
    return 0;
}
