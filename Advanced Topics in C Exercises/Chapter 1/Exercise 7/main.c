#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char pergjigjet[21];
    int piket;
}kandidati;

void renditSipasId(kandidati kandidatet[100]){
    int i = 1;
    kandidati kanditati1 = kandidatet[0];
    while(kandidatet[i].id != 0){
        if(kanditati1.id < kandidatet[i].id){
           kandidati tmp = kanditati1;
           kanditati1 = kandidatet[i];
           kandidatet[i] = tmp;
        }
        i++;
    }
}

int llogaritPiket(kandidati kandidatet[100]){
    int i = 0, piketGjithsej = 0;
    char pergjigjetSakt[21];
    strcpy(pergjigjetSakt,"BECDCBAADEBACBAEDDBE");
    while(kandidatet[i].id != 0){
        int j;
        for(j = 0; j < 20; j++){
            if(kandidatet[i].pergjigjet[j] == 'X'){
                continue;
            }
            if(kandidatet[i].pergjigjet[j] == pergjigjetSakt[j]){
                kandidatet[i].piket += 4;
            }
            else{
                kandidatet[i].piket--;
            }
        }
        piketGjithsej += kandidatet[i].piket;
        i++;
    }
    return piketGjithsej;
}

int main()
{
    FILE *exam = fopen("exam.txt", "r");
    if(exam == NULL){
        printf("\n\n\t\tSkedari i pergjigjeve nuk u lexua me sukses!!\n\n");
        return 0;
    }
    kandidati kandidatet[100] = {};
    int i = 0;
    while(1){
        if(fscanf(exam, "%d %s", &kandidatet[i].id, kandidatet[i].pergjigjet) != EOF){
           i++;
        }
        else{
            break;
        }
    }
    renditSipasId(kandidatet);
    int piketGjithsej = llogaritPiket(kandidatet);
    i = 0;
    while(kandidatet[i].id != 0){
        printf("%d %d\n", kandidatet[i].id, kandidatet[i].piket);
        i++;
    }
    printf("Piket mesatare per te gjithe studentet jane: %f", piketGjithsej/ (i * 1.0));
    return 0;
}
