#include <stdio.h>
#include <stdlib.h>

#define aSize 10
#define bSize 10

int main()
{
    int a[aSize] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10}, b[bSize] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
    int c[aSize + aSize];
    int i = 0, j = bSize - 1, k = 0;
    while((i < aSize) && (j >= 0)){
        if(a[i] > b[j]){
            c[k] = b[j];
            j--;
            k++;
        }
        else{
            c[k] = a[i];
            i++;
            k++;
        }
    }
    if(i == aSize){
        while(j >= 0){
            c[k] = b[j];
            k++;
            j--;
        }
    }
    else{
        while(i < aSize){
            c[k] = a[i];
            k++;
            i++;
        }
    }
    for(i = 0; i < 20; i++){
        printf("%d ", c[i]);
    }
    return 0;
}
