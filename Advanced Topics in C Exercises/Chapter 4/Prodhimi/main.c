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

shElementi mblidh2numra(shElementi numriI, shElementi numriII){
    shElementi shuma = NULL, shumaFund;
    VendosElementNeFund(&shuma, &shumaFund,0);          // vendosim bitin e shenejes 0 dukeqen se po merremi me numra +
    int shumashifrave = 0, mbetja = 0;                  // ruajme shumen e shifrave dhe mbetjen
    if (numriI != NULL){
        numriI = numriI->iRradhs;           // anashkalojme bitin e shenjes
    }
    if(numriII != NULL){
        numriII = numriII->iRradhs;
    }
    while((numriI != NULL) && (numriII != NULL)){
        shumashifrave = numriI->info + numriII->info + mbetja;  // kemi 3 raste se si mund te jete shuma
        if(shumashifrave >= 10){             //nese shuma eshte me e madhe se dhjete
            shumashifrave -= 10;        // pjesen e njesheve e leme te shuma dhe e ruajme te lista e shumes
            mbetja = 1;                 // pjesen e dhjeceve e ruajme te mbetja
        }
        else{               // nese shuma eshte me e vogel se 10 e ruajme ne listen e shumes sic eshte
            mbetja = 0;     // mbetja eshte 0 dhe shuma
        }
        VendosElementNeFund(&shuma, &shumaFund, shumashifrave);
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
            VendosElementNeFund(&shuma, &shumaFund, shumashifrave); // pastaj e shtojme ne listen e shumes sepse mund te kemi
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
            VendosElementNeFund(&shuma, &shumaFund, shumashifrave);
            numriI = numriI->iRradhs;
        }
    }
    if(mbetja == 1){
        VendosElementNeFund(&shuma, &shumaFund, 1);
    }
    return shuma;
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

int merrNumerNgaPerdoruesi(shElementi *aElementiI, shElementi *aElementiF){
    int sasia = 0;
    char c;
    while(1){
        c = getchar();
        if(c == '\n'){
            break;
        }
        if((c < '0') || (c > '9')){
            printf("\n\n\t\tVetme numra!!\n\n");
            fshiList(aElementiI, aElementiF);
            return -1;
        }
        else{
            VendosElementNeFillim(aElementiI, aElementiF, c - '0');
            sasia++;
        }
    }
    VendosElementNeFillim(aElementiI, aElementiF, 0);
    return sasia;
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

void kopjoList(shElementi *lista1, shElementi *lista1F, shElementi *lista2, shElementi *lista2F){
    shElementi shetites2 = *lista2;
    while(shetites2 != NULL){
        VendosElementNeFund(lista1, lista1F, shetites2->info);
        shetites2 = shetites2->iRradhs;
    }
}

void shumezoMe1shifer(shElementi *pPrgj, shElementi numri1, shElementi shifra, int dhjecet){
    shElementi pMe1shifer = NULL, pMe1shiferF, shetites = numri1;
    ruajDecimalNeListe(&pMe1shifer, &pMe1shiferF, 0);
    int p = 0, mbetja = 0;
    while(shetites != NULL){
        p = shetites->info * shifra->info + mbetja;
        if(p >= 10){
            mbetja = p / 10;
            p %= 10;
        }
        else{
            mbetja = 0;
        }
        VendosElementNeFund(&pMe1shifer, &pMe1shiferF, p);
        shetites = shetites->iRradhs;
    }
    while(dhjecet > 0){
        VendosElementNeFillim(&pMe1shifer->iRradhs, &pMe1shiferF, 0);
        dhjecet --;
    }
    *pPrgj = mblidh2numra(*pPrgj, pMe1shifer);
}

void prodhimiShumeShifra(shElementi *pprgj, shElementi *pprgjF, shElementi numri1, shElementi numri2){
    int dhjecet = 0, shenja = 0;
    if((numri1->info == 0) && (numri2->info == 0)){
        shenja = 0;
    }
    else if((numri1->info) * (numri2->info) == 0){
        shenja = 1;
    }
    numri1 = numri1->iRradhs;
    numri2 = numri2->iRradhs;
    while(numri2 != NULL){
        shumezoMe1shifer(pprgj, numri1, numri2, dhjecet);
        dhjecet++;
        numri2 = numri2->iRradhs;
    }
    (*pprgj)->info = shenja;
}

int printoNumrinDecimal(shElementi numri, shElementi numriF){
    int sasia = 0;
    if((numri == NULL) || (numri->iRradhs == NULL)){
        return 0;
    }
    int shenja = 0;
    if(numri->info == 1){
       shenja = 1;
    }
    ktheListenMbrapsht(&numri, &numriF);
    if(shenja == 1){
        printf("-");
        shElementi shetites = numri;
        while(shetites->iRradhs->iRradhs != NULL){
            printf("%d", shetites->info);
            sasia++;
            shetites = shetites ->iRradhs;
        }
    }
    else{
        shElementi shetites = numri;
        while(shetites->iRradhs!= NULL){
            printf("%d", shetites->info);
            sasia++;
            shetites = shetites ->iRradhs;
        }
    }
    return sasia;
}

int main(void)
{
    shElementi pprgj = NULL, pprgjF, numri1 = NULL, numri1F, numri2 = NULL, numri2F;
    ruajDecimalNeListe(&pprgj, &pprgjF, 0);
    int s1, s2;
    printf("\nVendos 1 numer me sa me shume shifra (KUJDES TASTJEREN!!)\n\n");
    s1 = merrNumerNgaPerdoruesi(&numri1, &numri1F);
    printf("\nVendos 1 numer me sa me shume shifra (KUJDES TASTJEREN!!)\n\n");
    s2 = merrNumerNgaPerdoruesi(&numri2, &numri2F);
    if(s1 > s2){
        prodhimiShumeShifra(&pprgj, &pprgjF, numri1, numri2);
    }
    else{
        prodhimiShumeShifra(&pprgj, &pprgjF, numri2, numri1);
    }
    printf("\n\t");
    printoNumrinDecimal(numri1, numri1F);
    printf("\n*\n\t");
    printoNumrinDecimal(numri2, numri2F);
    printf("\n_______________________________________________________________________________");
    printf("\n=\t");
    printf("\n\n\n\t%d",printoNumrinDecimal(pprgj, pprgjF));
    char c = getchar();
    return 0;
}
