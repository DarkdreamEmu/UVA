#include <stdio.h>

int main(){
    long long Fib[110];
    Fib[0]=0,Fib[1]=1;
    for(int i=2; i<=100; i++){
        Fib[i]=Fib[i-1]+Fib[i-2];
    }
    int n;
    while(scanf("%d",&n)&&n){
        printf("%lld\n",Fib[n]);
    }
    return 0;
}
