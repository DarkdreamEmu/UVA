#include "bits/stdc++.h"
using namespace std;

int dp[72][72][72];

int ans_me(int N,int M,int P){
    if(dp[N][M][P]!=-1)return dp[N][M][P];
    if(N==1){
        if(M-P>=0)return dp[N][M][P]=1;
        else return dp[N][M][P]=0;
    }
    int ans=0;
    for(int i=P; i<=M; i++){
        ans=ans+ans_me(N-1,M-i,P);
    }
    return dp[N][M][P]=ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int N,M,P;
        scanf("%d %d %d",&N,&M,&P);
        memset(dp,-1,sizeof(dp));
        int res=ans_me(N,M,P);
        printf("%d\n",res);
    }
    return 0;
}
