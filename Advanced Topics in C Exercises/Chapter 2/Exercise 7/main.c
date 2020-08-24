#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int ora;
    int minutat;
}ora;

int diferencaMinuta(ora o1, ora o2){
    if(o1.ora < o2.ora){
        return (o2.ora - o1.ora) * 60 + o2.minutat - o1.minutat;
    }
    if(o1.ora > o2.ora){
        return 24 * 60 - (o1.ora - o2.ora) * 60 + o1.minutat - o2.minutat;
    }
    if(o1.minutat > o2.minutat){
        return 24 * 60 - (o1.minutat - o2.minutat);
    }
    if(o1.minutat < o2.minutat){
        return o2.minutat - o1.minutat;
    }

    return 0;
}

int main()
{
    ora o1, o2;
    scanf("%d %d", &o1.ora, &o1.minutat);
    printf("\n");
    scanf("%d %d", &o2.ora, &o2.minutat);
    printf("%d", diferencaMinuta(o1,o2));
    return 0;
}
