#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Sum square difference
Problem 6
The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

long long shumaEkatrorve(int limitiNga1){
    if(limitiNga1 == 1){
        return 1;
    }
    return (limitiNga1 * limitiNga1) + shumaEkatrorve(limitiNga1 - 1);
}

long long katroriIshumes(int limitiNga1, int shuma){
    if(limitiNga1 == 1){
        shuma +=1;
        return shuma * shuma;
    }
    return katroriIshumes(limitiNga1 - 1, shuma + limitiNga1);
}

int main()
{
    printf("%lld  - % lld = %lld", katroriIshumes(100,0), shumaEkatrorve(100),
                                            (katroriIshumes(100,0) - shumaEkatrorve(100)));
    return 0;
}
