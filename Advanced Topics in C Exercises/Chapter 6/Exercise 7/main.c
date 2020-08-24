#include <stdio.h>
#include <stdlib.h>

int kerkimIrenditurRekursiv(int x, int v[], int n){
    if((n <= 0) || ( v[n - 1] < x)){
        return 0;
    }
    if( v [n - 1] == x){
        return 1;
    }
    return kerkimIrenditurRekursiv(x, v, n - 1);
}

void s(char c){
    if(c < 'H'){
        printf("%c ", c);
        s(c++);
    }
}

int main()
{
    s('C');
    return 0;
}
