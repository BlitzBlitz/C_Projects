#include <stdio.h>
#include <stdlib.h>
/*
Lexicographic permutations
Problem 24
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/
int main()
{
    int numrat[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, numrat1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, i, j;
    for(i = 0; i < 10; i++){
        int tmp = numrat[0];
        numrat[0] = numrat[i];
        numrat[i] = tmp;
        for(j = i + 1; j < 10; j++){
            int tmp = numrat[i];
            numrat[i] = numrat[j];
            numrat[j] = tmp;
        }
    }
    for(i = 0; i < 10; i++){
        printf("%d ", numrat[i]);
    }
    return 0;
}
