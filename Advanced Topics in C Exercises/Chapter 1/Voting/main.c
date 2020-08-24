#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define numriArtistve 10

typedef struct a{
    char emri[20];
    int index;
    long unsigned int votat;
}artisti, *shArtisti;

int lexo_artistet(artisti artistet[]){
    FILE *votat = fopen("votes.txt","r");
    if(votat == NULL){
        printf("\n\n\t\tVotat nuk u lexuan me sukses!!\n\n");
        fclose(votat);
        return -1;
    }
    int i = 0;
    while(i < numriArtistve){
        if((fscanf(votat, "%s %d %ld", artistet[i].emri, &artistet[i].index, &artistet[i].votat)) != EOF){
            i++;
        }
        else{
            break;
        }
    }
    fclose(votat);
    return 1;
}

void renditSipasVotave(artisti artistet[]){
    int i, j;
    artisti key;
    for(i = 1; i < numriArtistve; i++){
        j = i;
        while((artistet[j].votat > artistet[j - 1].votat) && (j > 0)){
            key = artistet[j];
            artistet[j] = artistet[j - 1];
            artistet[j - 1] = key;
            j--;
        }
    }
}

int main(){
    artisti artistet[numriArtistve] = {};
    if(lexo_artistet(artistet) == -1){
        return 0;
    }
    int vota;
    while(vota != 0){
        printf("\n\tVendosni voten per artistin e preferuar 1-10.\n");
        printf("\n\tVendosni 0 per te mbyllur votimin.\n\t");
        scanf("%d", &vota);
        if(vota == 0){
            printf("\n\tVotimi mbaroj me sukses!!");
            break;
        }
        if((vota > 10)||(vota < 1)){
            printf("\n\n\t\tVota eshte e pavlefshme!\n\n");
            continue;
        }
        else{
            artistet[vota - 1].votat++;
        }
    }
    FILE *votat = fopen("votes.txt","w");
    FILE *rezultatet = fopen("results.txt","w");
    int i = 0;
    while(i < numriArtistve){
        fprintf(votat, "%s %d %ld\n", artistet[i].emri, artistet[i].index, artistet[i].votat);
        fprintf(rezultatet, "%s %d %ld\n", artistet[i].emri, artistet[i].index, artistet[i].votat);
        i++;
    }
    renditSipasVotave(artistet);
    i = 0;
    while(i < numriArtistve){
        fprintf(rezultatet, "\n%s %d %ld", artistet[i].emri, artistet[i].index, artistet[i].votat);
        i++;
    }
    fclose(votat);
    fclose(rezultatet);
    return 0;
}
