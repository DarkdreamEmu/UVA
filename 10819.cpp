#include "bits/stdc++.h"
using namespace std;

int taka[110],flavour[110];
int money,num;
int dp[110][10001];

int ans_me(int i,int w){
    if(w>money&&money<1800)return -10000;
    if(w>money+200)return -10000;
    if(i==num){
        if(w>money&&w<=2000)return -10000;
        return 0;
    }
    if(dp[i][w]!=-1)return dp[i][w];
    return dp[i][w]=max(ans_me(i+1,w),ans_me(i+1,w+taka[i])+flavour[i]);
}

int main(){
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d",&money,&num)==2){
        for(int i=0; i<num; i++){
            scanf("%d %d",&taka[i],&flavour[i]);
        }
        memset(dp,-1,sizeof(dp));
        int res=ans_me(0,0);
        printf("%d\n",res);
    }
    return 0;
}
