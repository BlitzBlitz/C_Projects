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

void zevendesoShkronja(shElementi aElementiI,char shkronja1, char shkronja2){
    while(aElementiI != NULL){                  // persakohe ka elementi ne list
        if(aElementiI->shkronja == shkronja1){      // nese gjejm nje shkronje te ngjashme me sh1
            aElementiI->shkronja = shkronja2;       // e zv me sh2
        }
        aElementiI = aElementiI->iRradhs;
    }
}

void ngaTeVoglaNeTeMedha(shElementi aElementI){
    if(aElementI == NULL){
        return;
    }
    while(aElementI != NULL){
        if((aElementI->shkronja >= 'A') &&(aElementI->shkronja <= 'Z')){ // nese gjejm element qe jan shkronja te medha
            aElementI->shkronja += 32;                                  // i kthejme ne te vogla
        }
        aElementI = aElementI->iRradhs;
    }
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

void fshiElement(shElementi *aElementI, shElementi *aElementiF, shElementi elementiPerTuFshir){
    if(*aElementI == NULL){
        return;
    }
    if((*aElementI)->shkronja == elementiPerTuFshir->shkronja){
        free(*aElementI);
        *aElementI = NULL;
        return;
    }
    shElementi shetites = *aElementI;
    while(shetites->iRradhs != NULL){
        if(shetites->iRradhs->shkronja == elementiPerTuFshir->shkronja){
            shElementi iVjeter = shetites->iRradhs;
            shetites->iRradhs = shetites->iRradhs->iRradhs;
            free(iVjeter);
            if(shetites->iRradhs == NULL){
                *aElementiF = shetites;
                break;
            }
        }
        shetites = shetites->iRradhs;
   }
}

void KtheNeTeVoglaDheRendit(shElementi *aElementiI, shElementi *aElementiF){
    if(aElementiI == NULL){
        return;
    }
    shElementi shetites = *aElementiI;
    ngaTeVoglaNeTeMedha(*aElementiI);
    while(shetites != NULL){
        if((shetites->shkronja < 'a') || (shetites->shkronja > 'z')){
            shElementi iVjeter = shetites;
            shetites = shetites->iRradhs;
            fshiElement(aElementiI, aElementiF, iVjeter);
            continue;
        }
        shetites = shetites->iRradhs;
    }
    renditListen(aElementiI, aElementiF);
}

int eshteS2pjeseEs1(shElementi s1, shElementi s2){
    shElementi shetites1 = s1, shetites3 = s1, shetites2 = s2;        //1 per te levizur te stringu par 2 per te levizur
    while(shetites1 != NULL){                                           // paralelisht te te dy stringjet
        while((shetites2 != NULL) && (shetites3 != NULL)){
            if(shetites3->shkronja != shetites2->shkronja){
                break;
            }
            if((shetites2->iRradhs == NULL) && (shetites2->shkronja == shetites3->shkronja)){
                return 1;
            }
            shetites2 = shetites2->iRradhs;
            shetites3 = shetites2->iRradhs;
        }
        shetites1 = shetites1->iRradhs;
        shetites2 = s2;
        shetites3 = shetites1;
    }
    return 0;
}

int main(void)
{
    shElementi s1 = NULL, s1f, s2 = NULL, s2f;
    VendosElementNeFund(&s1, &s1f,'a');
    VendosElementNeFund(&s1, &s1f,'B');
    VendosElementNeFund(&s1, &s1f,'1');
    VendosElementNeFund(&s1, &s1f,'1');
    printoList(s1);
    KtheNeTeVoglaDheRendit(&s1, &s1f);
    printoList(s1);
    return 0;
}
