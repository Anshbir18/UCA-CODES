#include <stdio.h>

int bitwiseXOR(int a,int b){
    return (~(~a&~b)&(~(a&b)));
}
int main() {
    int a=10;
    int b=15;
    printf("%d ",bitwiseXOR(a,b));
  

    return 0;
}
