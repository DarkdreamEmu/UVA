#include <bits/stdc++.h>
using namespace std;

int dp[110][110];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string a,b;
    int cs=1;
    while(getline(cin,a)&&a[0]!='#'){
        getline(cin,b);
        int n=a.size();
        int m=b.size();

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n",cs++,dp[n][m]);
    }
    return 0;
}
