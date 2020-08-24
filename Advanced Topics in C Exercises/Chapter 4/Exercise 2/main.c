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
    printf("\n");
    while(aElementiI != NULL){
        printf("%d-> ", aElementiI->info);
        aElementiI = aElementiI->iRradhs;
    }
    printf("NULL");
    printf("\n");
}

void ktheListenMbrapsht(shElementi *aElementiI, shElementi *aElementiF){
    if(*aElementiI == NULL){    // kontrollojm nese lista ka 0
        return;
    }
    shElementi elemeniI = *aElementiI;  // ruajme adresen fillestare te 1
    while(elemeniI->iRradhs != NULL){           // derisa te cojme elementin e pare ne fund
        shElementi iRi = elemeniI->iRradhs->iRradhs;    //ruajme adresen e elementit te 3 qe te bejme lidhjen me te parin
        elemeniI->iRradhs->iRradhs = *aElementiI;       // elemenetin e 2 e kalojme ne fillim
        *aElementiI = elemeniI->iRradhs;                // => elementi 2 behet i pari
        elemeniI->iRradhs = iRi;                        // bejme lidhjen e 1 me 3
    }
    *aElementiF = elemeniI;                             // elementi i pare behet i fundit
}


int main(){
    shElementi elementiI = NULL, elementiF;
    VendosElementNeFund(&elementiI, &elementiF, 2);
    VendosElementNeFund(&elementiI, &elementiF, 12);
    printoList(elementiI);
    ktheListenMbrapsht(&elementiI, &elementiF);
    printoList(elementiI);
    return 0;
}
