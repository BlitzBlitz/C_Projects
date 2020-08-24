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

void fshiList(shElementi *aElementiI, shElementi *aElementiF){
    while(*aElementiI != NULL){                     // persakohe nuk jemi ne fund te listes
        shElementi iVjeter = (*aElementiI)->iRradhs;    // ruajme adresen e elementit te rradhes
        free(*aElementiI);                              // fshijme adresen ku jemi ishim me pare
        *aElementiI = iVjeter;                          // kalojme te elementi i rradhes
    }
    *aElementiI = NULL;                 // i bejme null dhe adresn e pare dhe te fundit te listes
    *aElementiF = NULL;
}
int main()
{
    shElementi aElementiI = NULL, aElementiF;
    VendosElementNeFund(&aElementiI, &aElementiF, 10);
    VendosElementNeFund(&aElementiI, &aElementiF, 10);
    VendosElementNeFund(&aElementiI, &aElementiF, 10);
    VendosElementNeFund(&aElementiI, &aElementiF, 10);
    VendosElementNeFund(&aElementiI, &aElementiF, 10);
    VendosElementNeFund(&aElementiI, &aElementiF, 10);
    printoList(aElementiI);
    fshiList(&aElementiI, &aElementiF);
    printf("\n");
    printoList(aElementiI);
    return 0;
}
