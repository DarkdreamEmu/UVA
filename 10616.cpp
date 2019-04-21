#include "bits/stdc++.h"
using namespace std;

int take[205];
int dp[205][205][20];
int num,d,n,cnt=0,m;

int ans_me(int ind,int sum,int cnt){
    if(cnt==num){
        if(sum%d==0)return 1;
        else return 0;
    }
    if(ind>=n)return 0;
    if(dp[ind][sum][cnt]!=-1)return dp[ind][sum][cnt];
    return dp[ind][sum][cnt]=ans_me(ind+1,sum%d,cnt)+ans_me(ind+1,(sum+take[ind])%d,cnt+1);
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int q,cs=1;
    while(scanf("%d %d",&n,&m)&&(m+n)){
        for(int i=0; i<n; i++){
            scanf("%d",&take[i]);
        }
        printf("SET %d:\n",cs++);
        int que=1;
        while(m--){
            scanf("%d %d",&d,&num);
            memset(dp,-1,sizeof(dp));
            printf("QUERY %d: %d\n",que++,ans_me(0,0,0));
        }
    }
    return 0;
}
