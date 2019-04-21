#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int edit_distance(string a,string b,int n,int m){

    for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
    }
    for (int j = 0; j <= n; j++) {
            dp[j][0] = j;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
            }
        }
    }
    return dp[n][m];
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string a,b;
    int n,m;
    while(cin>>n>>a>>m>>b){
        int res=edit_distance(a,b,n,m);
        printf("%d\n",res);
    }
    return 0;
}
