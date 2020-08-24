#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    struct element *Prindi;
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
    iRi->Prindi = NULL;
    return iRi;
}

int vendosElementR(shElementi *rrenja, int info){
    if(*rrenja == NULL){
        shElementi iRi = rezervoHapsir(info);
        if(iRi == NULL){
            printf("\n\n\t\tNO MEMORY!!\n\n");
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
        return 0;
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
            return 0;
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

int vleraMeEmadhe(shElementi rrenja){
    if(rrenja->iDjatht == NULL){
        return rrenja->info;
    }
    return vleraMeEmadhe(rrenja->iDjatht);
}

void fshiElement(shElementi *rrenja, int x){
    if(*rrenja == NULL){
        return;
    }
    if((*rrenja)->info == x){               //nqs x esht ne rrenje 3 rastet me 0,1,2 femije
        if(((*rrenja)->iDjatht == NULL) &&((*rrenja)->iMajt == NULL)){
            free(*rrenja);
            *rrenja = NULL;
        }
        else if(((*rrenja)->iDjatht == NULL) && ((*rrenja)->iMajt != NULL)){
                shElementi fshije = *rrenja;
                *rrenja = (*rrenja)->iMajt;
                free(fshije);
            }
        else if(((*rrenja)->iDjatht != NULL) && ((*rrenja)->iMajt == NULL)){
            shElementi fshije = (*rrenja);
            (*rrenja) = (*rrenja)->iDjatht;
            free(fshije);
        }
        else if(((*rrenja)->iDjatht != NULL) && ((*rrenja)->iMajt != NULL)){
                int i = vleraMeEmadhe((*rrenja)->iMajt);
                (*rrenja)->info = i;
                fshiElement(&((*rrenja)->iMajt),i);
        }
        return;
    }
    if(((*rrenja)->iMajt != NULL) && ((*rrenja)->iMajt->info == x)){    // nqs x eshte ne te majte 3 raste
        if(((*rrenja)->iMajt->iDjatht == NULL) &&((*rrenja)->iMajt->iMajt == NULL)){        // duhet te shkojme nje hap para x
            free((*rrenja)->iMajt);         // ka 0 femij                               // qe te kemi munci tebejme lidhjet
            (*rrenja)->iMajt = NULL;                                      // nuk mund te shkojme mbrapa
        }                                                                   // sepse kemi vetem iMajt iDjatht
        else if(((*rrenja)->iMajt->iDjatht == NULL) && ((*rrenja)->iMajt->iMajt != NULL)){
            shElementi fshije = (*rrenja)->iMajt;  // ka 1 femije majtas
            (*rrenja)->iMajt = (*rrenja)->iMajt->iMajt;
            free(fshije);
        }
        else if(((*rrenja)->iMajt->iDjatht != NULL) && ((*rrenja)->iMajt->iMajt == NULL)){
            shElementi fshije = (*rrenja)->iMajt;
            (*rrenja)->iMajt = (*rrenja)->iMajt->iDjatht;       // ka 1 femije djahtas
            free(fshije);
            }
        else if(((*rrenja)->iMajt->iDjatht != NULL) && ((*rrenja)->iMajt->iMajt != NULL)){// ka 2 femije
            int i = vleraMeEmadhe((*rrenja)->iMajt->iMajt);// ky element eshte me i madhi i numrave qe jane me te vegjel se
            (*rrenja)->iMajt->info = i;                             // elementi qe do fshihet => ruhet pema BINARE
            fshiElement(&((*rrenja)->iMajt->iMajt),i);
        }
    }
    if(((*rrenja)->iDjatht != NULL) && ((*rrenja)->iDjatht->info == x)){    // nqs x eshte ne te djathte 3 raste
        if(((*rrenja)->iDjatht->iDjatht == NULL) && ((*rrenja)->iDjatht->iMajt == NULL)){
            free((*rrenja)->iDjatht);
            (*rrenja)->iDjatht = NULL;
        }
        else if(((*rrenja)->iDjatht->iDjatht == NULL) && ((*rrenja)->iDjatht->iMajt != NULL)){
            shElementi fshije = (*rrenja)->iDjatht;
            (*rrenja)->iDjatht = (*rrenja)->iDjatht->iMajt;
            free(fshije);
        }
        else if(((*rrenja)->iDjatht->iDjatht != NULL) && ((*rrenja)->iDjatht->iMajt == NULL)){
            shElementi fshije = (*rrenja)->iDjatht;
            (*rrenja)->iDjatht = (*rrenja)->iDjatht->iDjatht;
            free(fshije);
        }
        else if (((*rrenja)->iDjatht->iDjatht != NULL) && ((*rrenja)->iDjatht->iMajt != NULL)){
            int i = vleraMeEmadhe((*rrenja)->iDjatht->iMajt);
            (*rrenja)->iDjatht->info = i;
            fshiElement(&((*rrenja)->iDjatht->iMajt),i);
        }
    }
    if(x < (*rrenja)->info){                        //
        fshiElement(&((*rrenja)->iMajt), x);
    }
    else if(x > (*rrenja)->info){
        fshiElement(&((*rrenja)->iDjatht), x);
    }
    return;
}

int main()
{
    shElementi rrenja = NULL;
    vendosElementR(&rrenja, 112);
    vendosElementR(&rrenja, 13);
    vendosElementR(&rrenja, 123);
    vendosElementR(&rrenja, 113);
    vendosElementR(&rrenja, 11113);
    vendosElementR(&rrenja, -113);
    vendosElementR(&rrenja, 114);
    vendosElementR(&rrenja, 115);
    vendosElementR(&rrenja, 183);
    vendosElementR(&rrenja, 163);
    printoPreOrder(rrenja);
    printf("\nVendos numrin qe doni te fshini: ");
    int numer;
    scanf("%d", &numer);
    fshiElement(&rrenja, numer);
    printf("\n");
    printoPreOrder(rrenja);
    return 0;
}
