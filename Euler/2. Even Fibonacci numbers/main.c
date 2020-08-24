#include <stdio.h>
#include <stdlib.h>
/*
typedef struct eListe{
    int info;
    struct eLista* Para;
    struct eLista* Mbrapa;
}eListe, *shListe;

shListe rezervoHapsirPerElement(int numri){
    shListe iRi = (shListe)malloc(sizeof(eListe));
    iRi->info = numri;
    iRi->Mbrapa = NULL;
    iRi->Para = NULL;
    return iRi;
}

void shtoElement(shListe *aElementiPare, shListe *aElementiFund, int numri){
    shListe iRi = rezervoHapsirPerElement(numri);
    if(*aElementiPare == NULL){
       *aElementiPare = iRi;
       *aElementiFund = iRi;
    }
    else{
        (*aElementiFund)->Mbrapa = iRi;
        iRi->Para = *aElementiFund;
        *aElementiFund = iRi;
    }
}
*/
int main()
{
    int k1 = 1, k2 = 2, k3 = 0, shumaCifteve = 2;
    printf("%d\n%d\n", k1, k2);
    while(k3 < 4000000){
        k3 = k2 + k1;
        k1 = k2;
        k2 = k3;
        printf("%d\n", k3);
        if(k3 % 2 == 0){
            shumaCifteve += k3;
            printf("\t%d\n", k3);
        }
    }
    printf("\n\n\t%d", shumaCifteve);
    return 0;
}
