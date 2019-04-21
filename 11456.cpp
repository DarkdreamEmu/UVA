#include <bits/stdc++.h>
using namespace std;

int ar[2001],dp1[2001],dp2[2001];

int main(){
    int n;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&ar[i]);
        }
        for(int i=n-1; i>=0; i--){
            dp1[i]=1;
            for(int j=i+1; j<n; j++){
                if(ar[i]<ar[j]){
                    dp1[i]=max(dp1[j]+1,dp1[i]);
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            dp2[i]=1;
            for(int j=i+1; j<n; j++){
                if(ar[i]>ar[j]){
                    dp2[i]=max(dp2[j]+1,dp2[i]);
                }
            }
        }
        int res=0;
        for(int i=0; i<n; i++){
            res=max(res,dp1[i]+dp2[i]-1);
        }
        printf("%d\n",res);
    }
    return 0;
}
