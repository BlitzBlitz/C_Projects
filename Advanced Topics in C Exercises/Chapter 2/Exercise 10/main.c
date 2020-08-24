#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int metra;
    int centimetra;
}distanca;

typedef struct {
    char emri[30];
    distanca distanca1;
}atleti;

int krahasoGjatesite(distanca gjatesia1, distanca gjatesia2){
    if(gjatesia1.metra > gjatesia2.metra){
        return 1;
    }
    else if(gjatesia1.metra < gjatesia2.metra){
        return -1;
    }
    if(gjatesia1.centimetra > gjatesia2.centimetra){
        return 1;
    }
    else if(gjatesia1.centimetra < gjatesia2.centimetra){
        return -1;
    }
    return 0;
}

void vendosNeVektor(atleti atlet1, atleti atletet[]){
    int i = 0;
    while(atletet[i].distanca1.metra != 0){
        if(krahasoGjatesite(atlet1.distanca1, atletet[i].distanca1) == 1){
            atleti tmp = atlet1;
            atlet1 = atletet[i];
            atletet[i] = tmp;
        }
        i++;
    }
    if(atletet[i].distanca1.metra == 0){
        atletet[i] = atlet1;
    }
}

int lexoAtlete(atleti atletet[]){
    FILE *sAtletet = fopen("atletet.txt","r");
    if(sAtletet == NULL){
        printf("\n\n\t\tAtletet nuk u lexuan me sukses!\n\n");
        return -1;
    }
    atleti atleti1;
    while(1){
        if(fscanf(sAtletet,"%s %d %d", atleti1.emri, &atleti1.distanca1.metra, &atleti1.distanca1.centimetra) != EOF){
            vendosNeVektor(atleti1, atletet);
        }
        else{
            break;
        }
    }
    return 0;
}

int main()
{
    atleti atletet[100] = {};
    if (lexoAtlete(atletet) == -1){
        return 0;
    }
    int i = 0;
    if(atletet[i].distanca1.metra == 0){
        printf("\n\n\t\tNuk ka asnje lojtar te rregjistruar!\n\n");
    }
    while(atletet[i].distanca1.metra != 0){
        printf("%s %d %d\n", atletet[i].emri, atletet[i].distanca1.metra, atletet[i].distanca1.centimetra);
        i++;
    }
    return 0;
}
