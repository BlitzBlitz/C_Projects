#include <stdio.h>
#include <stdlib.h>

void printoMeHapsira(long int numri){
    if(numri == 0){
        return;
    }
    printoMeHapsira(numri / 10);
    printf("%d ", numri % 10);
}

int main()
{
    printoMeHapsira(1000);
    return 0;
}
