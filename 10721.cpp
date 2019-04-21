#include "bits/stdc++.h"
using namespace std;

long long dp[52][52][52];

long long ans_me(int n,int k,int m){
    if(dp[n][k][m]!=-1)return dp[n][k][m];
    if(k==0&&n==0)return dp[n][k][m]=1LL;
    if(k==0)return dp[n][k][m]=0LL;
    long long ans=0;
    for(int i=1; i<=m; i++){
        if(n-i>=0)ans=ans+ans_me(n-i,k-1,m);
        else break;
    }
    return dp[n][k][m]=ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,k,m;
    while(scanf("%d %d %d",&n,&k,&m)==3){
        memset(dp,-1,sizeof(dp));
        long long res=ans_me(n,k,m);
        printf("%lld\n",res);
    }
    return 0;
}
