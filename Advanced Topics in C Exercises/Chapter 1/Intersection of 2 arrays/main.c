#include <stdio.h>
#include <stdlib.h>

#define VleramaxCrr 11
#define VleramaxRr  10

int kerkoBinary(int vlera, int teRenditur[]){
    int i = 0, j = VleramaxRr - 1;
    while(i <= j){
        if(vlera == teRenditur[(i + j) / 2]){
            return 1;
        }
        if(vlera > teRenditur[(i + j) / 2]){
            i = (i + j) / 2 + 1;
        }
        if(vlera < teRenditur[(i + j) / 2]){
            j = (i + j) / 2 - 1;
        }
    }
    return 0;
}

int main()
{
    int teCrregullt[VleramaxCrr] = {12,34,2,534,2213,1,3,7,5,6}, teRenditur[VleramaxRr] = {1,2,3,4,5,6,7,8,9,10}, sasia = 0;
    int i;
    for(i = 0; i < VleramaxCrr; i++){
        if(kerkoBinary(teCrregullt[i],teRenditur)){
            sasia++;
        }
    }
    printf("%d",sasia);
    return 0;
}
