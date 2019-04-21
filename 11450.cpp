#include <bits/stdc++.h>
using namespace std;

int M,C,res=-100000000,k;
vector<int>take[30];
int dp[25][220];

void reset(){
    memset(dp,0,sizeof(dp));
    for(int i=0; i<30; i++){
        take[i].clear();
    }
}

void ans_me(int ind,int sum){
    if(ind==C){
        if(sum<=M&&sum>res){
            res=sum;
        }
        return ;
    }
    if(sum>M)return ;
    if(dp[ind][sum])return ;
    dp[ind][sum]=1;
    for(int i=0; i<take[ind].size(); i++){
        ans_me(ind+1,sum+take[ind][i]);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        reset();
        scanf("%d %d",&M,&C);
        for(int i=0; i<C; i++){
            int k;
            scanf("%d",&k);
            while(k--){
                int amount;
                scanf("%d",&amount);
                take[i].push_back(amount);
            }
        }
        ans_me(0,0);
        if(res==-100000000)puts("no solution");
        else printf("%d\n",res);
        res=-100000000;
    }
    return 0;
}
