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

shElementi kerkoPreOrderR(shElementi rrenja, int x){
    if(rrenja == NULL){
        return rrenja;
    }
    else if(rrenja->info == x){
        return rrenja;
    }
    return kerkoPreOrderR(rrenja->iMajt,x);
    return kerkoPreOrderR(rrenja->iDjatht,x);
}

int main()
{
    shElementi rrenja = NULL;
    vendosElementR(&rrenja, 12);
    vendosElementR(&rrenja, -12);
    vendosElementR(&rrenja, 1);
    vendosElementR(&rrenja, 0);
    rrenja = kerkoPreOrderR(rrenja, 1);
    printf("%d",rrenja->info);
    return 0;
}
