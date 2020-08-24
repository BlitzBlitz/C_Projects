#include <stdio.h>
#include <math.h>


int main (void) {
    long long i, numri, sasia1 = 0, sasia2 = 1, numriImadh;

    for(i = 1; i < 1000000; i++){
        sasia2 = 0;
        numri = i;
        while(numri != 1){
            sasia2++;
            if(numri % 2 == 0){
                numri /= 2;
            }
            else if(numri % 2 == 1){
                numri = 3 * numri + 1;
            }
        }
        if(sasia2 > sasia1){
            sasia1 = sasia2;
            numriImadh = i;
        }
    }
    printf("%lld ", numriImadh);
    return 0;
}
