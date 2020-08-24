#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ndodhetShkronjaNeFjale(char shkronja, char fjala[]){
    int i;
    for(i = 0; i < strlen(fjala); i++){
        if(fjala[i] == shkronja){
            return 1;
        }
    }
    return 0;
}

int janFjaletAnagrame(char fjala1[], char fjala2[]){
    int i = 0;
    if(strlen(fjala1) != strlen(fjala2)){
        return 0;
    }
    while(fjala1[i] != '\0'){
        printf("%c\n",fjala1[i]);
        if(!ndodhetShkronjaNeFjale(fjala1[i],fjala2)){
            return 0;
        }
        i++;
    }
    return 1;
}

int main()
{
    char fjalet[100][40];
    int i, j;
    for(i = 0; i < 100; i++){
        for(j = i + 1; j < 100; j++){
            if(janFjaletAnagrame(fjalet[i],fjalet[j])){
                printf("\n%s %s\n", fjalet[i], fjalet[j]);
            }
        }
    }
    return 0;
}
