#include <bits/stdc++.h>
using namespace std;

int tower1[110];
int tower2[110];
int DP[110][110];

int lcs(int m,int n){
    for(int i=0; i<=m; i++){
        DP[i][0]=0;
    }
    for(int i=0; i<=n; i++){
        DP[0][i]=0;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(tower1[i]==tower2[j]){
                DP[i][j]=DP[i-1][j-1]+1;
            }
            else{
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    return DP[m][n];
}

int main(){
    int t1,t2,cs=1;
    bool ok=false;
    while(scanf("%d%d",&t1,&t2)&&(t1+t2)){
        for(int i=1; i<=t1; i++){
            scanf("%d",&tower1[i]);
        }
        for(int i=1; i<=t2; i++){
            scanf("%d",&tower2[i]);
        }
        int res=lcs(t1,t2);
        printf("Twin Towers #%d\n",cs++);
        printf("Number of Tiles : %d\n\n",res);
    }
    return 0;
}
