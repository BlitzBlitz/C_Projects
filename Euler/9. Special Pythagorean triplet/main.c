#include <stdio.h>
#include <stdlib.h>
/*
Special Pythagorean triplet
Problem 9
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

int eshteTreshePitagoriane(int a, int b, int c){
    if(a*a + b*b == c*c){
        return 1;
    }
    return 0;
}

void TreshjaSpecialePitagoriane(){


}

int main()
{
    printf("Hello world!\n");
    return 0;
}
