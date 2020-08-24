#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int info;
    struct element *iRradhs;
}element, *shElementi;

shElementi rezervoHapsire(int n){
    shElementi iRi = (shElementi)(malloc(sizeof(element)));
    if(iRi == NULL){
        return iRi;
    }
    iRi->info = n;
    iRi->iRradhs = NULL;
    return iRi;
}

void VendosElementNeFund(shElementi *aElementI, shElementi *aElementF, int n){
    shElementi iRi = rezervoHapsire(n);
    if(*aElementI == NULL){
        *aElementI = iRi;
        *aElementF = iRi;
        return;
    }
    else{
        (*aElementF)->iRradhs = iRi;
        *aElementF = iRi;
    }
}

void printoList(shElementi aElementiI){
    while(aElementiI != NULL){
        printf("%d-> ", aElementiI->info);
        aElementiI = aElementiI->iRradhs;
    }
    printf("NULL");
}

void VendosElementNePozicion(shElementi *aElementiI, shElementi *aElementiF, int nr, int poz){
    shElementi iRi = rezervoHapsire(nr);
    if(poz <= 0){                       // nese pozicioni eshte negativ ose 0 elementi vendoset ne fillim
        iRi->iRradhs = (*aElementiI);
        *aElementiI = iRi;
    }
    else{                                           // nese esht per tu ven ne nje pozicion tjt athere kalojme
        shElementi shetites = *aElementiI;          // elementet nje nga nje derisa te shkojme te pozicioni i duhur
        while(shetites != NULL){
            if(poz == 1){                           // kur shkojme ne pozicion bejme lidhjen dhe fusim elementin ne list
                iRi->iRradhs = shetites->iRradhs;
                shetites->iRradhs = iRi;
                return;
            }
            poz--;              // cdo element qe kalojme zbresim me 1 pozicionin
            shetites = shetites->iRradhs;
        }
        (*aElementiF)->iRradhs = iRi;
        *aElementiF = iRi;                // nese poz eshte me i madh se sasia e elementeve athere elementi vendoset ne fund
    }
}

int main()
{
    shElementi aElementiI = NULL, aElementiF;
    VendosElementNeFund(&aElementiI, &aElementiF,10);
    VendosElementNeFund(&aElementiI, &aElementiF,10);
    VendosElementNeFund(&aElementiI, &aElementiF,11);
    VendosElementNeFund(&aElementiI, &aElementiF,10);
    VendosElementNeFund(&aElementiI, &aElementiF,13);
    printoList(aElementiI);
    VendosElementNePozicion(&aElementiI, &aElementiF, 12, -1);
    printf("\n");
    printoList(aElementiI);
    printf("\n %d <=:=> %d", aElementiI->info, aElementiF->info);
    return 0;
}
