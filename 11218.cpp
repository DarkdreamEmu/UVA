#include "bits/stdc++.h"
using namespace std;

int SET(int mask,int pos){return (mask|(1<<pos));}
int check(int mask,int pos){return (mask&(1<<pos));}

int dp[1<<12];
int a[100],b[100],c[100],pro[100];
int n;

int ans_me(int mask){
    if(mask==(1<<9)-1)return 0;
    if(dp[mask]!=-1)return dp[mask];
    int ans=-INT_MAX;
    for(int i=0; i<n; i++){
        if(!check(mask,a[i]) && !check(mask,b[i]) &&!check(mask,c[i])){
            int newmask=SET(mask,a[i]);
            newmask=SET(newmask,b[i]);
            newmask=SET(newmask,c[i]);
            ans=max(ans,ans_me(newmask)+pro[i]);
        }
    }
    return dp[mask]=ans;
}

int main(){
    int cs=1;
    while(scanf("%d",&n)&&n!=0){
        for(int i=0; i<n; i++){
            cin>>a[i]>>b[i]>>c[i]>>pro[i];
            a[i]--;
            b[i]--;
            c[i]--;
        }
        memset(dp,-1,sizeof(dp));
        int ans=ans_me(0);
        if(ans<0)ans=-1;
        printf("Case %d: %d\n",cs++,ans);

    }
    return 0;
}
