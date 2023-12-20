#include <stdio.h>

int conditionalOperator(int n,int y,int z){
    int ans=((n>>31)|((~n+1)>>31));
    
    return (ans&y)|((~ans)&z);
}
int main() {
   int n=-10;
   printf("%d \n",conditionalOperator(n,4,5));
    return 0;
}
