#include "bits/stdc++.h"
using namespace std;

int n,m;
int dp[110][110];
int mod=1000000;

int ans_me(int kk,int nn){
    if(dp[kk][nn]!=-1)return dp[kk][nn];
    if(kk==1)return dp[kk][nn]=1;
    int ans=0;
    for(int i=0; i<=nn; i++){
        ans=(ans%mod+(ans_me(kk-1,i)%mod))%mod;
    }
    return dp[kk][nn]=ans;
}

int main(){
    while(scanf("%d %d",&n,&m)&&(n+m)){
        memset(dp,-1,sizeof(dp));
        int res=ans_me(m,n);
        printf("%d\n",res);
    }
    return 0;
}
