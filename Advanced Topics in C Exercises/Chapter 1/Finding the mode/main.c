#include <stdio.h>
#include <stdlib.h>

#define SasiaVlerave 100

int kerkimBinar(int vlera, int vlerat[2][SasiaVlerave], int i){
    int p0 = 0;
    while(p0 <= i){
        if(vlera == vlerat[0][(p0 + i) / 2]){
            return (p0 + i) / 2;
        }
        if(vlera > vlerat[0][(p0 + i) / 2]){
            p0 = (p0 + i) / 2 + 1;
        }
        else{
            i = (p0 + i) / 2 - 1;
        }
    }
    return -1;
}

void vendosNeRendRrites(int vlera, int vlerat[2][SasiaVlerave]){
    int i = 0, sasiaEvleres = 1;
    while(1){
        if(vlerat[0][i] == 0){
            vlerat[0][i] = vlera;
            vlerat[1][i] = 1;
            break;
        }
        if(vlerat[0][i] > vlera){
            int tmp = vlera;
            vlera = vlerat[0][i];
            vlerat[0][i] = tmp;
            int Stmp = sasiaEvleres;
            sasiaEvleres = vlerat[1][i];
            vlerat[1][i] = Stmp;
        }
        i++;
    }
}

int main()
{
    int vlerat[2][SasiaVlerave] = {}, i, vlera; // 1 rresht per vlerat 1 per sasine e perseritjes se vleres
    for(i = 0; i < SasiaVlerave; i++){
        printf("Vendos nje numer pozitiv: ");
        printf("\nVendos 0 per te shfaqur moden: ");
        fflush(stdin);
        scanf("%d", &vlera);
        if(vlera == 0){
            break;
        }
        if(vlera < 0){
            printf("\n\t\tVetem vlera pozitive!!\n");
            i--;
            continue;
        }
        int vleraKerkimit = kerkimBinar(vlera,vlerat,i);
        if( vleraKerkimit == -1){
            vendosNeRendRrites(vlera,vlerat);
        }
        else{
            vlerat[1][vleraKerkimit]++;
            i--;
        }
    }
    i = 0;
    int sasiaModa = 0, moda = 0;
    while((vlerat[0][i] != 0) && (i < SasiaVlerave)){
        if(sasiaModa < vlerat[1][i]){
            moda = vlerat[0][i];
            sasiaModa = vlerat[1][i];
        }
        i++;
    }
    if(moda == 0){
        printf("\n\n\t\tNuk ka asnje numer te rregjistruar!\n\n");
        return 0;
    }
    printf("\nModa eshte %d me sasi perseritjeje %d", moda, sasiaModa);
    return 0;
}
