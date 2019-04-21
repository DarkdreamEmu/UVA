#include "bits/stdc++.h"
using namespace std;

long long a[10010];

long long power(long long x,long long y,long long mod){
    long long res=1;
    x = x%mod;
    while(y>0){
        if(y&1)res=(res*x)%mod;
        y = y>>1;
        x = (x*x) %mod;
    }
    return res;
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        long long n,k,mod,sum=0;
        scanf("%lld %lld %lld",&n,&k,&mod);
        for(int i=0; i<n; i++){
            scanf("%lld",&a[i]);
            sum=( (sum%mod)+(a[i]%mod) )%mod;
        }
        long long tot=power(n,k-1,mod);
        tot=( (tot%mod)*(k%mod) )%mod;
        long long ans=((tot%mod)*(sum%mod))%mod;
        printf("Case %d: %lld\n",cs++,ans);
    }
    return 0;
}

