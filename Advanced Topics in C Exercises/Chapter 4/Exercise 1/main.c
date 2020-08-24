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

void shtoElement(shElementi *aElementI, shElementi *aElementF, int n){
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

int eshteListaRrites(shElementi aElementiI){
    if(aElementiI == NULL){
        return 0;
    }
    while(aElementiI -> iRradhs != NULL){
        if(aElementiI->info > aElementiI->iRradhs->info){
            return 0;
        }
        aElementiI = aElementiI->iRradhs;
    }
    return 1;
}

int main(void)
{
    shElementi aElementiI = NULL, aElementiF;
    printoList(aElementiI);
    printf("\n%d", eshteListaRrites(aElementiI));
    return 0;
}
