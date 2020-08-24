#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char emri[20];
    long unsigned int numriTel;
}personi;


int kerkoPerson(personi personi1,personi personat[], int pFundit){
    int p1 = 0;
    while(p1 < pFundit){
        if(strcmp(personi1.emri, personat[(p1 + pFundit) / 2].emri) == 0){
            return 1;
        }
        if(strcmp(personi1.emri, personat[(p1 + pFundit) / 2].emri) < 0){
            pFundit = (p1 + pFundit) / 2 - 1;
        }
        if(strcmp(personi1.emri, personat[(p1 + pFundit) / 2].emri) > 0){
            p1 = (p1 + pFundit) / 2 + 1;
        }
    }
    return -1;
}

void rregjistroPerson(personi personat[], int *i){
    personi personi1;
    printf("Vendos Emrin: ");
    scanf("%s",personi1.emri);
    if(kerkoPerson(personi1, personat, *i) == 1){
        printf("\n\n\t\tPersoni eshte i rregjistruar!\n\n");
        return;
    }
    printf("Vendos numrin e telefonit: ");
    scanf("%ld", &personi1.numriTel);
    int j = 0;
    while(1){
        if(personat[j].numriTel == 0){
            personat[j] = personi1;
            break;
        }
        if((strcmp(personat[j].emri,personi1.emri) > 0) && ((personat[j].numriTel) != 0)){
            personi tmp = personi1;
            personi1 = personat[j];
            personat[j] = tmp;
        }
        j++;
    }
    (*i)++;
}


int main(){
    int zgjedhje, i = 0;
    personi personat[100] = {};
    while(1){
        printf("\nShtypni 1 per te rregjistruar person!!\n");
        printf("Shtypni 2 per te kerkuar person!!\n");
        printf("Shtypni 0 per te mbyllur programin!!\n");
        scanf("%d", &zgjedhje);
        if((zgjedhje < 0)||(zgjedhje > 2)){
            printf("\n\n\t\tVendosni nje nga tre zgjedhjet!!\n");
            continue;
        }
        personi personi1;
        switch (zgjedhje){
            case 1:
                rregjistroPerson(personat, &i);
                break;
            case 2:
                printf("Vendos emrin e personit: \n\t");
                scanf("%s",personi1.emri);
                if(kerkoPerson(personi1,personat,i) == 1){
                    printf("\n\n\t\tPersoni eshte i rregjistruar!\n\n");
                }
                else{
                    printf("\n\n\t\tPersoni nuk eshte i rregjistruar!\n\n");
                }
                break;
            case 0:
                i = 0;
                while(personat[i].numriTel != 0){
                    printf("%s %ld\n", personat[i].emri, personat[i].numriTel);
                    i++;
                }
                return 0;
        }
    }

    return 0;
}
