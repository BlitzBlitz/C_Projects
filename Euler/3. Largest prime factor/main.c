#include <stdio.h>
#include <stdlib.h>
int eshtNumerPrim(long long numri){
    long long i;
    for(i = 2; i * i <= numri; i++){
        if(numri % i == 0){
            return 0;
        }
    }
    return 1;
}


/*
Largest prime factor
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?


long long largestPrimeFactor(long long number){
    long long LPF = -1, x = number / 2;
    while(x > 2){
        if(number % x == 0){
            if(eshtNumerPrim(x)){
                LPF = x;
                return LPF;
            }
        }
        x--;
    }
    return LPF;
}




typedef struct eListe{
    long long info;
    struct eListe* iRradhs;
}eListe, *shListe;

shListe rezervoHapsirPerElement(long long n){
    shListe iRi = (shListe)malloc(sizeof(eListe));
    iRi->info = n;
    iRi->iRradhs = NULL;
    return iRi;
}

void shtoElementNeList(shListe *aElementiPare, shListe *aElementiFundit, long long n){
    shListe iRi = rezervoHapsirPerElement(n);
    if(*aElementiPare == NULL){
        *aElementiPare = iRi;
        *aElementiFundit = iRi;
    }
    else{
        (*aElementiFundit)->iRradhs = iRi;
        *aElementiFundit = iRi;
    }
}

void mbushListenMePjestues(shListe *aElementiPare, shListe *aElementiFundit, long long numri){
    long long x = numei / 2;
    while(x > 2){
        if(numri % x == 0){
            shtoElementNeList(aElementiPare,aElementiFundit,x);
        }
        x--;
    }
}

void prinoList(shListe aElementiPare){
    shListe shetites = aElementiPare;
    while(shetites != NULL){
        printf("%ld\n", shetites->info);
        shetites = shetites ->iRradhs;
    }
    printf("NULL");
}

long long pjestuesiMeImadhPrim(shListe aElementiPare, long long numri){
    shListe shetites = aElementiPare;
    while(shetites != NULL){
        if(eshtNumerPrim(shetites->info)){
            return shetites->info;
        }
        shetites = shetites ->iRradhs;
    }
    return -1;
}
*/

long long pjestuesiMeImadhPrim2(long long numri){
    long long i;
    for(i = 2; i < numri/2; i++){
        if((numri % i == 0 ) && ( eshtNumerPrim(numri / i))){
            return numri / i;
        }
    }
    return -1;
}

int main()
{
    printf("%lld", pjestuesiMeImadhPrim2(600851475143));
    printf("\n%d", eshtNumerPrim(6857));
    return 0;
}
