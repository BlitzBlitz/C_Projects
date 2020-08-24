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

void ktheNeNumerBinar(shElementi *aElementiI, shElementi *aElementiF, long long numri){
    if(numri < 0){
        numri *= -1;                                             // biti i pare per shenjen!!
        VendosElementNeFund(aElementiI, aElementiF, 1);
    }
    else{
        VendosElementNeFund(aElementiI, aElementiF, 0);
    }
    while(numri != 0){
        VendosElementNeFund(aElementiI, aElementiF, numri % 2);   // vendosim mbetjen qe del nga pjestimi i numrit me 2 ne list
        numri = numri / 2;                                        // numrin e pjestojme per 2;
    }
}

int main()
{
    shElementi aElementiI = NULL, aElementiF;
    ktheNeNumerBinar(&aElementiI, &aElementiF, 2);
    printoList(aElementiI);
    return 0;
}
