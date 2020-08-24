#include <stdio.h>
#include <stdlib.h>

void selectionSortRecursiv(int v[], int n){
    if(n <= 1){   // indeksi = n - 1
        return;
    }
    if(v[n - 1] > v [n - 2]){
        int tmp = v[n - 1];
        v[n - 1] = v[n - 2];
        v[n - 2] = tmp;
    }
    selectionSortRecursiv(v, n - 1);
}

int main()
{
    int v[5] = {2, 1, 0, 3, -1};
    selectionSortRecursiv(v, 5);
    printf("%d %d %d %d %d", v[0], v[1], v[2], v[3], v[4]);
    return 0;
}
