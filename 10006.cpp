#include <bits/stdc++.h>
using namespace std;

bool mark[70000];

#define lli long long int

inline lli bigmod(lli a,lli b,lli m)               {if(b==0)return 1%m;lli x=bigmod(a,b/2,m);x=(x*x)%m;if(b%2==1){x=(x*a)%m;}return x;}

void sieve(int n){
    memset(mark,true,sizeof(mark));
    mark[1]=mark[0]=false;
    for(int i=2; i*i<=n; i++){
        if(mark[i]==true){
            for(int j=i+i; j<=n; j+=i){
                mark[j]=false;
            }
        }
    }
}

int main(){
    sieve(70000);
    int n;
    while(scanf("%d",&n)&&n){
        if(mark[n]){
            printf("%d is normal.\n",n);
            continue;
        }
        bool ok=true;
        for(int i=2; i<n; i++){
            if(bigmod(i,n,n)!=i){
                ok=false;
                break;
            }
        }
        if(ok){
            printf("The number %d is a Carmichael number.\n",n);
        }
        else{
            printf("%d is normal.\n",n);
        }
    }
    return 0;
}
