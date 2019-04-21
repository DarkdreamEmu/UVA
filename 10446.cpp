#include "bits/stdc++.h"
using namespace std;

unsigned long long dp[72][72];

long long ans_me(int n,int cnt){
    if(n<=1)return 0LL;
    if(dp[n][cnt]!=-1)return dp[n][cnt];
    long long ans=0;
    for(int i=1; i<=cnt; i++){
        ans+=ans_me(n-i,cnt)+1;
    }
    return dp[n][cnt]=ans;
}

int main(){
    int n,cnt,cs=1;
    while(scanf("%d %d",&n,&cnt)==2&&(n<=60)){
        memset(dp,-1,sizeof(dp));
        unsigned long long res=ans_me(n,cnt)+1LL;
        printf("Case %d: ",cs++);cout<<res<<endl;
    }
    return 0;
}
