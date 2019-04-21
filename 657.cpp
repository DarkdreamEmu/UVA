#include <bits/stdc++.h>
using namespace std;

char s[52][52];
int cnt=0;
int m,n;
vector<int>res;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int i,int j){
    if(i<0||i==n||j<0||j==m)return false;
    else return true;
}

void dfs1(int i,int j){
    if(!valid(i,j)||s[i][j]!='X'){
        return ;
    }
    s[i][j]='*';
    for(int k=0; k<4; k++){
        int R=dx[k]+i;
        int C=dy[k]+j;
        dfs1(R,C);
    }
}

void dfs(int i,int j){
    if(!valid(i,j)||s[i][j]=='.'){
        return ;
    }
    if(s[i][j]=='X'){
        cnt++;
        dfs1(i,j);
    }
    s[i][j]='.';
    for(int k=0; k<4; k++){
        int R=dx[k]+i;
        int C=dy[k]+j;
        dfs(R,C);
    }
}

int main(){
    int cs=1;
    while(scanf("%d%d",&m,&n)&&(n+m)){
        for(int i=0; i<n; i++){
            cin>>s[i];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(s[i][j]!='.'){
                    cnt=0;
                    dfs(i,j);
                    res.push_back(cnt);
                }
            }
        }
        sort(res.begin(),res.end());
        printf("Throw %d\n",cs++);
        printf("%d",res[0]);
        for(int i=1; i<res.size(); i++){
            printf(" %d",res[i]);
        }
        printf("\n\n");
        res.clear();
    }
    return 0;
}
