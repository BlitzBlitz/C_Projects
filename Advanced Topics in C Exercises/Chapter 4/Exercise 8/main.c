#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void ktheNeNumerBinar(shElementi *aElementiI, shElementi *aElementiF, long long numri){
    if(numri < 0){
        numri *= -1;                                             // biti i pare per shenjen!!
        VendosElementNeFund(aElementiI, aElementiF, 1);
    }
    else{
        VendosElementNeFund(aElementiI, aElementiF, 0);
    }
    while(numri != 0){
        VendosElementNeFund(aElementiI, aElementiF, numri % 2);
        numri = numri / 2;
    }
}

long long ktheNeDecimal(shElementi aElementiI){
    int shenja = 0;
    if((aElementiI != NULL) && (aElementiI->info == 1)){            // nese biti i pare eshte 1 atehere ruajme qe shenja eshte
        shenja = 1;                                                 // negative
        aElementiI = aElementiI->iRradhs;
    }
    long long numriDecimal = 0;
    int fuqia = 0;
    while(aElementiI != NULL){
        if((aElementiI->info) == 1){                        // cdo bit qe esht 1 te numri shtojme fuqine e n-te te 2-shit
            numriDecimal += pow(2,fuqia);
        }
        fuqia++;                                            // rrisim fuqine kalojme te elementi tjt
        aElementiI = aElementiI->iRradhs;
    }
    if(shenja == 1){
        numriDecimal *= -1;             // nese shenja eshte 1 e kthejme numrin negativ
    }
    return numriDecimal;
}

int main()
{
    shElementi aElementiI = NULL, aElementiF;
    ktheNeNumerBinar(&aElementiI, &aElementiF, -128);
    printoList(aElementiI);
    printf("%ld",ktheNeDecimal(aElementiI));
    return 0;
}
