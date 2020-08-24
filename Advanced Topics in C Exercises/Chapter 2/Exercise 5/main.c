#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dita;
    int muaj;
    int viti;
} data, *shDate;

int krahasoDatat(shDate data1, shDate data2){
    if(data1->viti > data2->viti){
        return -1;
    }
    else{
        return 1;
    }
    if(data1->muaj > data2->muaj){
        return -1;
    }
    else{
        return 1;
    }
    if(data1->dita > data2->dita){
        return -1;
    }
    else{
        return 1;
    }
    return 0;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
