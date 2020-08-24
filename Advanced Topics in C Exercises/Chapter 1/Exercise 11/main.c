#include <stdio.h>
#include <stdlib.h>

#define aSize 10

int main()
{
    int i = 0, j = aSize - 1, k = 0, a[aSize] = {1,2,3,4,7,8,9,10,6,5},b[aSize];
    while((i < aSize) && (j >= 0)){
        if(a[i] < a[j]){
            b[k] = a[i];
            i++;
            k++;
        }
        else{
            b[k] = a[j];
            j--;
            k++;
        }
    }
    for(i = 0; i < 10; i++){
        printf("%d ", b[i]);
    }
    return 0;
}
