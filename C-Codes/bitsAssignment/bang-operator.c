
#include <stdio.h>

int bangOperator(int n){
    int ans=((n>>31)|((~n+1)>>31));
    return ans+1;
    
}
int main() {
   int n=0;
   printf("%d \n",bangOperator(n));
    return 0;
}
