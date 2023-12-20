#include <stdio.h>

int getByte(int n,int x){
    int shift=x*8;
    n=n>>shift;
    
    int bitMask=0xFF;
    
    return n&bitMask;
}

int main() {
   int n=0x12345678;
   printf("%d \n",getByte(n,1));
    return 0;
}
