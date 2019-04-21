#include <bits/stdc++.h>
using namespace std;

int cut[100];
int visited[100][100];
int dp[100][100];

int ans_me(int beg,int en){
    if(en-beg==1)return 0;
    if(visited[beg][en])return dp[beg][en];
    int res=1000000;
    for(int i=beg+1; i<en; i++){
        res=min(cut[en]-cut[beg]+ans_me(beg,i)+ans_me(i,en),res);
    }
    visited[beg][en]=1;
    dp[beg][en]=res;
    return res;
}

int main(){
    int L;
    while(scanf("%d",&L)&&L){
        memset(visited,0,sizeof(visited));
        int n;
        scanf("%d",&n);
        cut[0]=0;
        for(int i=1; i<=n; i++){
            scanf("%d",&cut[i]);
        }
        cut[n+1]=L;
        printf("The minimum cutting is %d.\n",ans_me(0,n+1));
    }
    return 0;
}
