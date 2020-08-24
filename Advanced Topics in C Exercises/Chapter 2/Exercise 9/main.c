#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int metra;
    int centimetra;
}gjatesia;

int krahasoGjatesite(gjatesia gjatesia1, gjatesia gjatesia2){
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

gjatesia diferencaEgjatesice(gjatesia gjatesia1, gjatesia gjatesia2){
    gjatesia diferenca;
    diferenca.metra = gjatesia1.metra - gjatesia2.centimetra;
    diferenca.centimetra = gjatesia1.centimetra - gjatesia2.centimetra;
    return diferenca;
}

gjatesia shumaEgjatesive(gjatesia gjatesia1, gjatesia gjatesia2){
    gjatesia diferenca;
    diferenca.metra = gjatesia1.metra + gjatesia2.centimetra;
    diferenca.centimetra = gjatesia1.centimetra + gjatesia2.centimetra;
    return diferenca;
}

int main()
{

    return 0;
}
