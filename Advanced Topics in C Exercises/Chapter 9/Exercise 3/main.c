#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    struct element *iMajt;
    int info;
    struct element *iDjatht;
}element, *shElementi;

shElementi rezervoHapsir(int info){
    shElementi iRi = (shElementi)malloc(sizeof(element));
    if(iRi == NULL){
        return iRi;
    }
    iRi->info = info;
    iRi->iDjatht = NULL;
    iRi->iMajt = NULL;
    return iRi;
}

int vendosElementR(shElementi *rrenja, int info){
    if(*rrenja == NULL){
        shElementi iRi = rezervoHapsir(info);
        if(iRi == NULL){
            return -1;
        }
        *rrenja = iRi;
        return 1;
    }
    if(info < (*rrenja)->info){
        return vendosElementR(&((*rrenja)->iMajt), info);
    }
    else if(info > (*rrenja)->info){
        return vendosElementR(&((*rrenja)->iDjatht), info);
    }
    else{
        return -1;
    }
}

int vendosElement(shElementi *rrenja, int info){
    shElementi iRi = (shElementi)malloc(sizeof(element));
    if(iRi == NULL){
        return -1;
    }
    if(*rrenja == NULL){
        *rrenja = iRi;
        return 1;
    }
    shElementi shetites = *rrenja;
    while(1){
        if(shetites->info < info){
            printf("%p", shetites->iDjatht);
            if(shetites->iDjatht == NULL){
                shetites->iDjatht = iRi;
                return 1;
            }
            shetites = shetites->iDjatht;
        }
        else if(shetites->info > info){
            if(shetites->iMajt == NULL){
                shetites->iMajt = iRi;
                return 1;
            }
            shetites = shetites->iMajt;
        }
        else{
            return -1;
        }
    }
    return -1;
}

void printoPreOrder(shElementi rrenja){
    if(rrenja == NULL){
        return;
    }
    printf("%d ", rrenja->info);
    printoPreOrder(rrenja->iMajt);
    printoPreOrder(rrenja->iDjatht);
}

shElementi fshiMinimum(shElementi rrenja){
    if(rrenja == NULL){
        return NULL;
    }
    if(rrenja->iMajt == NULL){
        shElementi rrenjaRe = rrenja->iDjatht;
        free(rrenja);
        return rrenjaRe;
    }
    shElementi shetites = rrenja;
    while(1){
        if((shetites->iMajt != NULL) && (shetites->iMajt->iMajt == NULL)){
           free(shetites->iMajt);
           shetites->iMajt = NULL;
           break;
        }
        shetites = shetites->iMajt;
    }
    return rrenja;
}

void fshiMinimumR(shElementi *rrenja){
    if(*rrenja == NULL){
        return;
    }
    if((*rrenja)->iMajt == NULL){
        shElementi rrenjaRe = (*rrenja)->iDjatht;
        free(*rrenja);
        *rrenja = rrenjaRe;
        return;
    }
    if(((*rrenja)->iMajt != NULL) && ((*rrenja)->iMajt->iMajt == NULL)){
           free((*rrenja)->iMajt);
           (*rrenja)->iMajt = NULL;
           return;
    }
    fshiMinimumR(&((*rrenja)->iMajt));
}

int main()
{
    shElementi rrenja = NULL;
    vendosElementR(&rrenja, 12);
    vendosElementR(&rrenja, 13);
    printoPreOrder(rrenja);
    fshiMinimumR(&rrenja);
    printf("\n");
    printoPreOrder(rrenja);
    return 0;
}
