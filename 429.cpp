#include <bits/stdc++.h>
using namespace std;

#define mx 202

map<string,int>my;
vector<int>graph[mx];
bool visited[mx];
int dis[mx];
string stor[mx];

int dp[100][100];

int edit_distance(string a,string b){

    int n=a.size();
    int m=b.size();

    for(int j = 0; j <= m; j++){
            dp[0][j] = j;
    }
    for(int j = 0; j <= n; j++){
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

void bfs(int s,int des,string in){
    memset(visited,0,sizeof(visited));
    queue<int>q;
    q.push(s);
    dis[s]=0;
    visited[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==des){
            cout<<in;
            printf(" %d\n",dis[u]);
            break;
        }
        int sz=graph[u].size();
        for(int i=0; i<sz; i++){
            int x=graph[u][i];
            if(!visited[x]){
                visited[x]=1;
                dis[x]=dis[u]+1;
                q.push(x);
            }
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    cin.ignore();
    while(t--){
        string s;
        int ind=1;
        int n=0;
        while(cin>>s&&s!="*"){
            my[s]=ind++;
            stor[n]=s;
            n++;
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x=stor[i].size();
                int y=stor[j].size();
                if(x==y){
                    if(edit_distance(stor[i],stor[j])==1){
                        int u=my[stor[i]];
                        int v=my[stor[j]];
                        graph[u].push_back(v);
                        graph[v].push_back(u);
                    }
                }
            }
        }

        string sou,des;
        cin.ignore();
        string in;
        while(getline(cin,in)&&in.size()){
            stringstream ss(in);
            ss>>sou;
            ss>>des;
            int sss=my[sou];
            int ddd=my[des];
            bfs(sss,ddd,in);
        }
        if(t){
            printf("\n");
        }
        my.clear();
        for(int i=0; i<=n; i++){
            graph[i].clear();
        }
    }
    return 0;
}
