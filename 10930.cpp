#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int cs=1;
    while(scanf("%d",&n)==1){
        bool ok=true;
        int dp[1010];
        int ar[n+10];
        for(int i=0; i<n; i++){
            scanf("%d",&ar[i]);
        }
        if(ar[0]<1){
            ok=false;
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0; i<n; i++){
            for(int j=1000; j>=0; j--){
                if(dp[j]&&j+ar[i]<=1000){
                    dp[j+ar[i]]++;
                }
            }
        }
        for(int i=1; i<n; i++){
            if(ar[i]<=ar[i-1]){
                ok=false;
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(dp[ar[i]]>1){
                ok=false;
                break;
            }

        }
        printf ("Case #%d:", cs++);
        for(int i=0; i<n; i++){
             printf(" %d", ar[i]);
        }
        if(ok){
            printf("\nThis is an A-sequence.\n");
        }
        else{
            printf("\nThis is not an A-sequence.\n");
        }
    }
    return 0;
}
