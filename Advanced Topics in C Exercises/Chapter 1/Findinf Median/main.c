#include <stdio.h>
#include <stdlib.h>

#define maksimumi 100

void vendosVleren(int vlera, int vlerat[]){
    int i = 0;
    while(1){
        if(vlerat[i] == 0){
            vlerat[i] = vlera;
            return;
        }
        else if(vlera < vlerat[i]){
            int tmp = vlera;
            vlera = vlerat[i];
            vlerat[i] = tmp;
        }
        i++;
    }
}

int main(){
    int i = 0, vlera, vlerat[maksimumi] = {};
    do{
        printf("\nVendosni numrin pozitiv qe deshironi!!");
        printf("\nVendosni 0 per te afishur numrin median\n");
        scanf("%d", &vlera);
        if(vlera < 0){
            printf("\n\n\t\tVetem vlera pozitive!\n");
        }
        else if (vlera != 0) {
            vendosVleren(vlera, vlerat);
            i++;
        }
    }while(vlera != 0);
    i = (i - 1) / 2;
    int numriMedian = (vlerat[i] + vlerat[i + i % 2]) / 2;
    printf("%d", numriMedian);
    return 0;
}
