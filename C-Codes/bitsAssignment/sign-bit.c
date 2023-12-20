#include <stdio.h>


int signBit(int n){
    return (n>>31)|!!n;
}

int main() {
   int n=0;
   printf("%d \n",signBit(n));
    return 0;
}
