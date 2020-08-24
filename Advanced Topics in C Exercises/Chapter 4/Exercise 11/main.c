#include <stdio.h>
#include <stdlib.h>

typedef struct shkronja{
    char shkronja;
    struct shkronja *iRradhs;
}shkronja, *shShkronje;

shShkronje rezervoHapsire(char shkronja){
    shShkronje iRi = (shShkronje)(malloc(sizeof(shkronja)));
    if(iRi == NULL){
        return iRi;
    }
    iRi->shkronja = shkronja;
    iRi->iRradhs = NULL;
    return iRi;
}

void VendosElementNeFund(shShkronje *aElementI, shShkronje *aElementF, char shkronja){
    shShkronje iRi = rezervoHapsire(shkronja);
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

void fshiElement(shShkronje *aElementiI, shShkronje elementi){
    if(*aElementiI == NULL){
        return;
    }
    shShkronje shetites = *aElementiI;
    if(shetites == elementi){
        *aElementiI = elementi;
        free(elementi);
        return;
    }
    while(shetites->iRradhs != NULL){
        if(shetites->iRradhs == elementi){
            shShkronje perTuFshir = shetites->iRradhs;
            shetites->iRradhs = shetites->iRradhs->iRradhs;
            free(perTuFshir);
            return;
        }
        shetites = shetites->iRradhs;
    }
    if((shetites->iRradhs == NULL) && (shetites->iRradhs == elementi)){
        free(shetites->iRradhs);
        shetites->iRradhs = NULL;
    }
}

void printoList(shShkronje fjala){
    printf("\n");
    while(fjala != NULL){
        printf("%c ",fjala->shkronja);
        fjala = fjala->iRradhs;
    }
    printf("\n");
}

int janeFjaletAnagrama(shShkronje fjala1, shShkronje fjala2){
    if((fjala1 == NULL)&&(fjala2 != NULL)){                 // kontrollojme nese njera fjale eshte bosh dhe tjetra jo
        return 0;                                           // nese eshte e vertet fjalet smund te jene anagrama
    }
    else if ((fjala1 != NULL) && (fjala2 == NULL)){
        return 0;
    }
    shShkronje shetites;                // nese te dyja permbajne te pakten 1 fjale vazhdojme krahasimin
    while(fjala1 != NULL){
        shetites = fjala2;              // shetitesin e cojme te fjala e 2
        while(shetites != NULL){
            if(fjala1->shkronja == shetites->shkronja){     // per cdo shkrojnje te fjales1 kontrollojme nese gjendet te fjala2
                fshiElement(&fjala2, fjala1);           // nese gjendet e fshijme qe te mos na ngaterroje ne kontrollet e
                break;                                      // shkronjave te tjera dhe bejme break; per te vazhduar me
            }                                                   // shkronjat e tjera te fjales1
            else if((shetites->iRradhs == NULL) && (shetites->shkronja != fjala1->shkronja)){
                return 0;                   // nese jemi te fundi i fjales2 dhe nuk e kemi gjetur akoma shkronjen qe kekrojme
            }                           // do te thote qe kjo shkronje nuk ndodhet ne fjalen2 => fjala1 dhe 2 nuk jan anagrama
            shetites = shetites->iRradhs;
        }
        fjala1 = fjala1->iRradhs;
    }
    return 1;                   // nese kalon te gjitha kontrollet ose nese te dyja fjalet jan bosh fjalet jan anagrama
}

int main(void)
{
    shShkronje fjala1 = NULL, fundF1, fjala2 = NULL, fundF2;
    printf("%d", janeFjaletAnagrama(fjala1, fjala2));
    return 0;
}
