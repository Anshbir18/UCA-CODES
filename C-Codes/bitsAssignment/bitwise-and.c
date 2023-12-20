#include <stdio.h>

int bitwiseAnd(int a,int b){
    return ~((~a)|(~b));
}

int main() {
   int a=10;
   int b=15;
   printf("%d ",bitwiseAnd(a,b));

    return 0;
}
