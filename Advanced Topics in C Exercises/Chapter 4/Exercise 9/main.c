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
        numri *= -1;
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

shElementi mblidh2numraBinar(shElementi numriI, shElementi numriII){// mbledhim 2 numra pozitiv!
    shElementi shuma = NULL, shumaFund;                 // deklarojme 1 list per te ruajtur bitet e shumes
    VendosElementNeFund(&shuma, &shumaFund,0);          // vendosim bitin e shenjes 0 => shuma gjithmon pozitive
    int shuma2biteve = 0, mbetja = 0;
    numriI = numriI->iRradhs;                           // anashkalojme bitin e shenjes dukeqene se kemi vetem numra pozitiv
    numriII = numriII->iRradhs;
    while((numriI != NULL) && (numriII != NULL)){       // persako te dy numrat binar kane shifra bejme mbledhjen e tyre
        shuma2biteve = numriI->info + numriII->info + mbetja;
        if(shuma2biteve == 3){
            shuma2biteve = 1;
            mbetja = 1;
        }
        else if(shuma2biteve == 2){
            shuma2biteve = 0;
            mbetja = 1;
        }
        else{
            mbetja = 0;
        }
        VendosElementNeFund(&shuma, &shumaFund, shuma2biteve); // vendosim shumen te lista e shumes
        numriI = numriI->iRradhs;
        numriII = numriII->iRradhs;
    }
    if((numriI == NULL) && (numriII != NULL)){  // nese numri2 ka mbaruar por numri1 ka akoma bite
        while(numriII != NULL){                 // shtojme pjesen e mbetur te biteve te lista e shumes me te njejten menyre
            shuma2biteve = numriII->info + mbetja; // kujdes llogarisim njeher shumen me gjith mbetjen sepse mund te kemi
            if(shuma2biteve == 3){                  // mbetje nga shifra e fundit e numrit qe ka mbaruar
                shuma2biteve = 1;
                mbetja = 1;
            }
            if(shuma2biteve == 2){
                mbetja = 1;
                shuma2biteve = 0;
            }
            else{
                mbetja = 0;
            }
            VendosElementNeFund(&shuma, &shumaFund, shuma2biteve); // dhe me pas e shtojme te shuma
            numriII = numriII->iRradhs;
        }
    }
    else if((numriII == NULL) && (numriI != NULL)){ // e njejta gje nese ka mbaruar numri1
        while(numriI != NULL){
            shuma2biteve = numriI->info + mbetja;
            if(shuma2biteve == 3){
                shuma2biteve = 1;
                mbetja = 1;
            }
            else if(shuma2biteve == 2){
                mbetja = 1;
                shuma2biteve = 0;
            }
            else{
                mbetja = 0;
            }
            VendosElementNeFund(&shuma, &shumaFund, shuma2biteve);
            numriI = numriI->iRradhs;
        }
    }
    if(mbetja == 1){
        VendosElementNeFund(&shuma, &shumaFund, mbetja);
    }
    return shuma;
}

long long ktheNeDecimal(shElementi aElementiI){
    int shenja = 0;
    if((aElementiI != NULL) && (aElementiI->info == 1)){
        shenja = 1;
    }
    aElementiI = aElementiI->iRradhs;
    long long numriDecimal = 0;
    int fuqia = 0;
    while(aElementiI != NULL){
        if((aElementiI->info) == 1){
            numriDecimal += pow(2,fuqia);
        }
        fuqia++;
        aElementiI = aElementiI->iRradhs;
    }
    if(shenja == 1){
        numriDecimal *= -1;
    }
    return numriDecimal;
}


int main()
{
    shElementi numri1 = NULL, numri1fund, numri2 = NULL, numri2fund;
    ktheNeNumerBinar(&numri1, &numri1fund, 2222);
    ktheNeNumerBinar(&numri2, &numri2fund, 1);
    printoList(numri1);
    printoList(numri2);
    printoList(mblidh2numraBinar(numri1, numri2));
    printf("\n%ld", ktheNeDecimal(mblidh2numraBinar(numri1,numri2)));
    return 0;
}
