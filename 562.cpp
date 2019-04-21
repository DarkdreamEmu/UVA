#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int coin[n+10];
        int sum=0;
        int mn=1000;
        for(int i=0; i<n; i++){
            scanf("%d",&coin[i]);
            sum+=coin[i];
            mn=min(mn,coin[i]);
        }
        int limit=sum/2;
        int dp[limit+10];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0; i<n; i++){
            for(int j=limit; j>=0; j--){
                if(dp[j]&&(j+coin[i]<=limit)){
                    dp[j+coin[i]]=true;
                }
            }
        }
        int mx=0;
        for(int i=0; i<=limit; i++){
            if(dp[i]==true){
                mx=max(mx,i);
            }
        }
        //cout<<sum<<" "<<mx<<endl;
        printf("%d\n",sum-2*mx);
    }
    return 0;
}
