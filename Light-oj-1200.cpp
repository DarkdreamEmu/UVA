#include "bits/stdc++.h"
using namespace std;

int n,W;
int price[110];
int weight[110];
int dp[120][10020];

int ans_me(int ind,int sum){
    int X=0,Y=0,Z=0;
    if(ind>=n)return 0;
    if(sum>W)return 0;
    if(dp[ind][sum]!=-1)return dp[ind][sum];
    if(sum+weight[ind]<=W) X=ans_me(ind+1,sum+weight[ind])+price[ind];
    if(sum+weight[ind]<=W) Y=ans_me(ind,sum+weight[ind])+price[ind];
    Z=ans_me(ind+1,sum);
    return dp[ind][sum]=max(X,max(Y,Z));
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&W);
        for(int i=0; i<n; i++){
            int x;
            scanf("%d %d %d",&price[i],&x,&weight[i]);
            W=W-x*weight[i];
        }
        printf("Case %d: ",cs++);
        if(W<0)puts("Impossible");
        else{
            memset(dp,-1,sizeof(dp));
            int res=ans_me(0,0);
            printf("%d\n",res);
        }
    }
    return 0;
}
