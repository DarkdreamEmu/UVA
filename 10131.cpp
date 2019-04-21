#include "bits/stdc++.h"
using namespace std;

struct item{
    int W,IQ,ind;
};

bool cmp(item A,item B){
    if(A.W!=B.W)return A.W<B.W;
    else return A.IQ>B.IQ;
}

int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    item take[1100];
    int n=0;
    while(scanf("%d %d",&take[n].W,&take[n].IQ)==2){
        take[n].ind=n;
        n++;
    }
    sort(take,take+n,cmp);
    int dp[n+10],parent[n+10],start=0,ans=0;
    for(int i=n-1; i>=0; i--){
        dp[i]=1;
        parent[i]=-1;
        for(int j=i+1; j<n; j++){
            if(take[i].W<take[j].W&&take[i].IQ>take[j].IQ&&dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                parent[i]=j;
            }
        }
        if(dp[i]>ans){
            ans=dp[i];
            start=i;
        }
    }
    printf("%d\n",ans);
    for(int i=start; i!=-1; i=parent[i]){
        printf("%d\n",take[i].ind+1);
    }
    return 0;
}
