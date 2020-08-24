#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    char shkronja;
    struct element *iRradhs;
}element, *shElementi;

shElementi rezervoHapsire(char shkronja){
    shElementi iRi = (shElementi)(malloc(sizeof(element)));
    if(iRi == NULL){
        return iRi;
    }
    iRi->shkronja = shkronja;
    iRi->iRradhs = NULL;
    return iRi;
}

void VendosElementNeFund(shElementi *aElementI, shElementi *aElementF, char shkronja){
    shElementi iRi = rezervoHapsire(shkronja);
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
        printf("%c-> ", aElementiI->shkronja);
        aElementiI = aElementiI->iRradhs;
    }
    printf("NULL");
}

void renditListen(shElementi *aElementiI, shElementi *aElementiF){
    if(*aElementiI == NULL){        // lista ska element
        return;
    }
    if((*aElementiI)->iRradhs == NULL){
        return;                             // lista ka vetem 1 element
    }
    int i = 0, j = 1;
    shElementi shetites1 = *aElementiI, aElementiM = *aElementiI, aElementiParaM;
    while(shetites1 != NULL){
        while(shetites1->iRradhs != NULL){                      //gjejme adresen e elementit para elementit me te madh dhe adresen e elementit te madh
            if(shetites1->iRradhs->shkronja > aElementiM->shkronja){    // kontrollojme 1 hap mbrapa vendit ku ndodhemi qe te kemi munci te ruajme
                aElementiParaM = shetites1;                     // adresen e elementit para me te madhit
                aElementiM = shetites1->iRradhs;
            }
            shetites1 = shetites1->iRradhs;
        }
        if(aElementiM == *aElementiF){                      // nese elementi i madh ndodhet ne fund
            aElementiParaM->iRradhs = NULL;                 // elementit para tij foshen e rradhes e bejm null
            *aElementiF = aElementiParaM;                   // kjo ben qe  ky te jete elementi i fundit i listes tanime
            aElementiM->iRradhs = *aElementiI;              // te fundin e meparshem e lidhim me te parin e listes => i fundit behet i pari
            *aElementiI = aElementiM;
        }
        else if(aElementiM != * aElementiI){       // nese elementiM ndodhet ne mes athere bejme lidhjen midis elementit para tij
            aElementiParaM->iRradhs = aElementiM->iRradhs;         // dhe atij pas tij
            aElementiM->iRradhs = *aElementiI;         // vete elementin me te madh e nxjerrim ne fillim duke lidhur fushen e tij
            *aElementiI = aElementiM;                     // iRradhs me elementiI => ky elementi behet elementi i pare i listes
        }
        shetites1 = *aElementiI;        // cojme shetitesin ne fillim te elementi 2 pasi kemi cuar ne fillim te listes elementin me te madh
        for(i = 0; i < j; i++){             // qe kerkimi per elementin me te madh te 2 te vazhdoje pa elementin e pare me te madh
            if(i == j - 1){                     // ruajme gjithnje adresen para elementit me te madh per te ber lidhjet e nevojshme
                aElementiParaM = shetites1;
            }
            shetites1 = shetites1->iRradhs;
        }
        aElementiM = shetites1;
        j++;
    }
}

int main(){
    shElementi element1 = NULL, elementF;
    VendosElementNeFund(&element1, &elementF, 'b');
    VendosElementNeFund(&element1, &elementF, 'a');
    VendosElementNeFund(&element1, &elementF, 'z');
    VendosElementNeFund(&element1, &elementF, 'c');
    renditListen(&element1, &elementF);
    printoList(element1);
    return 0;
}
