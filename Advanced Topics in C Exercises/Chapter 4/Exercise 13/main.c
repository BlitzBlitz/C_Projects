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
        printf("%d", aElementiI->info);
        aElementiI = aElementiI->iRradhs;
    }
    printf("\n");
}

void VendosElementNeFillim(shElementi *aElementiI, shElementi *aElementiF, int n){
    shElementi iRi = rezervoHapsire(n);
    iRi->iRradhs = *aElementiI;
    if(*aElementiI == NULL){
        *aElementiF = iRi;
        *aElementiI = iRi;
    }
    else{
        *aElementiI = iRi;
    }
}

void mblidh2numra(shElementi numriI, shElementi numriII, shElementi *shuma ,shElementi *shumaFund){
    VendosElementNeFund(shuma, shumaFund,0);          // vendosim bitin e shenejes 0 dukeqen se po merremi me numra +
    int shumashifrave = 0, mbetja = 0;                  // ruajme shumen e shifrave dhe mbetjen
    numriI = numriI->iRradhs;           // anashkalojme bitin e shenjes
    numriII = numriII->iRradhs;
    while((numriI != NULL) && (numriII != NULL)){
        shumashifrave = numriI->info + numriII->info + mbetja;  // kemi 3 raste se si mund te jete shuma
        if(shumashifrave >= 10){             //nese shuma eshte me e madhe se dhjete
            shumashifrave -= 10;        // pjesen e njesheve e leme te shuma dhe e ruajme te lista e shumes
            mbetja = 1;                 // pjesen e dhjeceve e ruajme te mbetja
        }
        else{               // nese shuma eshte me e vogel se 10 e ruajme ne listen e shumes sic eshte
            mbetja = 0;     // mbetja eshte 0 dhe shuma
        }
        VendosElementNeFund(shuma, shumaFund, shumashifrave);
        numriI = numriI->iRradhs; // kalojme te shifrat e tjera
        numriII = numriII->iRradhs;
    }
    if((numriI == NULL) && (numriII != NULL)){ // nese numri2 ka mbaruar nga shifrat vazhdojme me numrin 1
        while(numriII != NULL){
            shumashifrave = numriII->info + mbetja; // vazhdojme si me pare !! llogarisim njeher shumen dhe mbetjen
            if(shumashifrave >= 10){
                shumashifrave -= 10;
                mbetja = 1;
            }
            else{
                mbetja = 0;
            }
            VendosElementNeFund(shuma, shumaFund, shumashifrave); // pastaj e shtojme ne listen e shumes sepse mund te kemi
            numriII = numriII->iRradhs;                             // mbetje nga shifra e fundit e numrit qe ka mbaruar
        }
    }
    else if((numriII == NULL) && (numriI != NULL)){
        while(numriI != NULL){
            shumashifrave = numriI->info + mbetja;
            if(shumashifrave >= 10){
                shumashifrave -= 10;
                mbetja = 1;
            }
            else{
                mbetja = 0;
            }
            VendosElementNeFund(shuma, shumaFund, shumashifrave);
            numriI = numriI->iRradhs;
        }
    }
    if(mbetja == 1){
        VendosElementNeFund(shuma, shumaFund, 1);
    }
}

void ruajDecimalNeListe(shElementi *aElementiI, shElementi *aElementiF, long long numri){
   if(numri < 0){
        VendosElementNeFund(aElementiI, aElementiF, 1);
   }
   else{
        VendosElementNeFund(aElementiI, aElementiF, 0);
   }
   while(numri != 0){
        VendosElementNeFund(aElementiI, aElementiF, numri % 10);
        numri /= 10;
   }
}

void fshiList(shElementi *aElementiI, shElementi *aElementiF){
    while(*aElementiI != NULL){
        shElementi iVjeter = *aElementiI;
        *aElementiI = (*aElementiI)->iRradhs;
        free(iVjeter);
    }
    *aElementiI = NULL;
    *aElementiF = NULL;
}

void merrNumerNgaPerdoruesi(shElementi *aElementiI, shElementi *aElementiF){
    char c;
    while(1){
        c = getchar();
        if(c == '\n'){
            break;
        }
        if((c < '0') || (c > '9')){
            printf("\n\n\t\tVetme numra!!\n\n");
            fshiList(aElementiI, aElementiF);
        }
        else{
            VendosElementNeFillim(aElementiI, aElementiF, c - '0');
        }
    }
    VendosElementNeFillim(aElementiI, aElementiF, 0);
}

void ktheListenMbrapsht(shElementi *aElementiI, shElementi *aElementiF){
    if(*aElementiI == NULL){    // kontrollojm nese lista ka 0
        return;
    }
    shElementi elemeniI = *aElementiI;  // ruajme adresen fillestare te 1
    while(elemeniI->iRradhs != NULL){
        shElementi iRi = elemeniI->iRradhs->iRradhs;
        elemeniI->iRradhs->iRradhs = *aElementiI;
        *aElementiI = elemeniI->iRradhs;
        elemeniI->iRradhs = iRi;
    }
    *aElementiF = elemeniI;
}


int main()
{
    shElementi numri1 = NULL, numri1fund, numri2 = NULL, numri2fund;
    printf("Vendos 1 numer pozitif: ");
    merrNumerNgaPerdoruesi(&numri1, &numri1fund);
    printf("\nVendos 1 numer pozitif: ");
    merrNumerNgaPerdoruesi(&numri2, &numri2fund);
    printf("Shuma e tyre eshte: ");
    shElementi shumaF, shuma = NULL;
    mblidh2numra(numri1,numri2, &shuma, &shumaF);
    ktheListenMbrapsht(&shuma, &shumaF);
    printoList(shuma);
    return 0;
}
