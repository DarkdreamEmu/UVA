#include "bits/stdc++.h"
using namespace std;

int L,S;
int ar[30];
long dp[40][40][600];

long ans_me(int l,int ind,int s){
    if(ind>26 || l>L || s>S)return 0;
    if(l==L && s==S)return 1;
    if(dp[ind][l][s]!=-1)return dp[ind][l][s];
    long ans=0;
    ans+=ans_me(l+1,ind+1,s+ar[ind]);
    ans+=ans_me(l,ind+1,s);
    return dp[ind][l][s]=ans;
}

int main(){
    int cs=1;
    for(int i=1; i<=26; i++)ar[i-1]=i;
    while(scanf("%d %d",&L,&S) &&(L+S)){
        memset(dp,-1,sizeof(dp));
        long ans=0;
        if(L<=26 && S<=380)ans=ans_me(0,0,0);
        printf("Case %d: %ld\n",cs++,ans);
    }
    return 0;
}

