#include <bits/stdc++.h>
using namespace std;

#define mx 100010

int dp[mx];

int LDS(int input[],int n){
    for(int i=0; i<n; i++){
        dp[i]=1;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(input[j]<=input[i]){
                dp[j]=max(dp[j],dp[i]+1);
            }
        }
    }
    int res=0;
    for(int i=0; i<n; i++){
    	res=max(res,dp[i]);
	}
    return res;
}


int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    int tes=1;
    int k;
    bool ok=false;
    while(scanf("%d",&k)&&k!=-1){
        if(ok){
            printf("\n");
        }
        ok=true;
        int a[111100];
        int i=0;
        a[i]=k;
        i++;
        while(scanf("%d",&a[i])&&a[i]!=-1){
            i++;
        }
        int res=LDS(a,i);
        printf("Test #%d\n",tes++);
        printf("  maximum possible interceptions: %d\n",res);
    }
    return 0;
}

