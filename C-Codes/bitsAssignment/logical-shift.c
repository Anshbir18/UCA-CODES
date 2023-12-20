#include <stdio.h>

int logicalShift(int n,int x){
    int bitMask=-1;
    bitMask=bitMask<<(32-x);
    bitMask=~bitMask;
    
    n=n>>x;
    
    return n&bitMask;
}

int main() {
   int n=10;
   printf("%d \n",logicalShift(n,2));
    return 0;
}
