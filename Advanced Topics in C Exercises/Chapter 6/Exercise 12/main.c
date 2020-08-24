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

int gjatesia(shElementi iPari){
    if(iPari == NULL){
        return 0;
    }
    return 1 + gjatesia(iPari->iRradhs);
}

int main()
{
    shElementi iPari = NULL, iFundit;
    VendosElementNeFund(&iPari, &iFundit, 12);
    VendosElementNeFund(&iPari, &iFundit, 12);

    printf("%d", gjatesia(iPari));
    return 0;
}
