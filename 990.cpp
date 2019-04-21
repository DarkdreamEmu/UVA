#include "bits/stdc++.h"
using namespace std;

int n;
int t,W;
int depth[1100];
int quantity[1100];
int dp[1100][1100];
int path[1100][1100];
vector<int>IND;

int ans_me(int ind,int sum){
    if(ind>=n)return 0;
    if(sum>t)return 0;
    if(dp[ind][sum]!=-1)return dp[ind][sum];
    int A=0,B=0;
    if((sum+(3*W*depth[ind]))<=t)A=ans_me(ind+1,sum+(3*W*depth[ind]))+quantity[ind];
    B=ans_me(ind+1,sum);
    if(A>B){
        path[ind][sum]=1;
    }
    else path[ind][sum]=2;
    return dp[ind][sum]=max(A,B);
}

int print(int ind,int sum){
    if(path[ind][sum]==-1)return 0;
    if(path[ind][sum]==1){
        IND.push_back(ind);
        return 1+print(ind+1,sum+(3*W*depth[ind]));
    }
    else return print(ind+1,sum);
}

int main(){
    bool ok=false;
    while(scanf("%d %d",&t,&W)==2){
        if(ok)printf("\n");
        ok=true;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d %d",&depth[i],&quantity[i]);
        }
        memset(dp,-1,sizeof(dp));
        memset(path,-1,sizeof(path));
        int res=ans_me(0,0);
        printf("%d\n",res);
        printf("%d\n",print(0,0));
        for(int i=0; i<IND.size(); i++){
            printf("%d %d\n",depth[IND[i]],quantity[IND[i]]);
        }
        IND.clear();
    }
    return 0;
}
