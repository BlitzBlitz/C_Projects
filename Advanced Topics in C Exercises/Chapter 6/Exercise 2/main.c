#include <stdio.h>
#include <stdlib.h>

void printoMePresje(int n){
    if(n < 1000){
        return;
    }printf("%d,",n % 1000);
    printoMePresje(n / 1000);

}

int main()
{
    int n;
    printf("Vendos 1 numer:\n");
    scanf("%d", &n);
    printoMePresje(n);
    return 0;
}
