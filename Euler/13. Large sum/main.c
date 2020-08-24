#include <stdio.h>
#include <stdlib.h>
/*
Large sum
Problem 13
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
*/
int main()
{
    FILE *shSkedari = fopen("Numri.txt","r");
    char c;
    int matrica[100][50], i, j, shumat[50] = {};
    for(i = 0; i < 100; i++){
        for(j = 0; j < 50; j++){
            if((c = fgetc(shSkedari)) != EOF){
                if(c == '\n'){
                    j--;
                    continue;
                }
                matrica[i][j] = c - 48;
            }
        }
    }
    fclose(shSkedari);
    for(i = 0; i < 100; i++){
        for(j = 0; j < 50; j++){
            printf("%d ", matrica[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < 50; i++){
        for(j = 0; j < 100; j++){
            shumat[i] += matrica[j][i];
        }
    }
    i = 49;
    int mbetje;
    printf("\n\n\n\n\n\n");
    while(i > 0){
        mbetje = shumat[i] / 10;
        shumat[i] %= 10;
        shumat [i - 1] += mbetje;
        i--;
    }
    for(i = 0; i < 50; i++){
        printf("%d ", shumat[i]);
    }
    return 0;
}
