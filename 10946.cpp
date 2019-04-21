#include <bits/stdc++.h>
using namespace std;

char s[55][55];
int freq[26];
int visited[55][55];
char ch;
int m,n,cnt=0,mx=0;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
vector<pair<int,char> >res;

bool valid(int i,int j){
    return ((i>=0&&i<m)&&(j>=0&&j<n));
}

void dfs(int i,int j){
    visited[i][j]=1;
    s[i][j]='.';
    cnt++;
    for(int k=0; k<4; k++){
        int R=dx[k]+i;
        int C=dy[k]+j;
        if(valid(R,C)&&!visited[R][C]&&s[R][C]==ch){
            dfs(R,C);
        }
    }
}

int main(){
    int cs=1;
    while(scanf("%d%d",&m,&n)&&(n+m)){
        for(int i=0; i<m; i++){
            scanf("%s",s[i]);
        }
        memset(visited,0,sizeof(visited));
        memset(freq,0,sizeof(freq));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]&&s[i][j]!='.'){
                    cnt=0;
                    ch=s[i][j];
                    dfs(i,j);
                    res.push_back(make_pair(ch,cnt));
                    mx=max(mx,cnt);
                }
            }
        }
        printf("Problem %d:\n",cs++);

        sort(res.begin(),res.end());
        int sz=res.size();

        for(int j=mx; j>=1; j--){
            for(int i=0; i<sz; i++){
                if(j==res[i].second){
                    printf("%c %d\n",res[i].first,j);
                }
            }
        }
        res.clear();
    }
    return 0;
}
