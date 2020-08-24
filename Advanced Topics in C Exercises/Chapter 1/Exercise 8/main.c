#include <stdio.h>
#include <stdlib.h>

#define aSize 10
#define bSize 10

int main()
{
    int a[aSize] = {100, 91, 81, 72, 6, 5, 4, 3, 2, 1}, b[bSize] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
    int c[aSize + aSize];
    int i = 0, j = 0, k = 0;
    while((i < aSize) && (j < bSize)){
        if(a[i] < b[j]){
            c[k] = b[j];
            j++;
            k++;
        }
        else{
            c[k] = a[i];
            i++;
            k++;
        }
    }
    if(i == aSize){
        while(j < bSize){
            c[k] = b[j];
            k++;
            j++;
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
