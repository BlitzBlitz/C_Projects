#include <stdio.h>
#include <stdlib.h>

int maxVektoriRekursiv(int max, int v[], int n){
    if(n <= 0){
        return max;
    }
    if(max < v[n - 1]){
        max = v[n - 1];
    }
    return maxVektoriRekursiv(max, v, n - 1);
}

int main()
{
    int v[5] = {1, 2, 33, -44, 3};
    printf("%d", maxVektoriRekursiv(v[0], v, 5));
    return 0;
}
