/**Algorithm Used: Kosaraju’s algorithm for strongly connected components**/

#include <bits/stdc++.h>
using namespace std;

const int mx=1010;

map<string,int>my;
vector<int>graph[mx];
vector<int>rev[mx];
vector<int>connected[mx];
stack<int>stk;
bool visited[mx];
int color[mx];
int n,m;
int mark=0;

void clean(){
    for(int i=0; i<=n; i++){
        graph[i].clear();
        rev[i].clear();
        connected[i].clear();
    }
    memset(visited,0,sizeof(visited));
    memset(color,0,sizeof(color));
    stk.empty();
    my.clear();
    mark=0;
}

void dfs(int u){
    color[u]=1;
    int sz=graph[u].size();
    for(int i=0; i<sz; i++){
        int v=graph[u][i];
        if(!color[v]){
            dfs(v);
        }
    }
    stk.push(u);
}

void dfs2(int u){
    connected[mark].push_back(u);
    visited[u]=1;
    int sz=rev[u].size();
    for(int i=0; i<sz; i++){
        int v=rev[u][i];
        if(!visited[v]){
            dfs2(v);
        }
    }
}

int Find_SCC(){
    for(int i=1; i<=n; i++){
        if(!color[i]){
            dfs(i);
        }
    }
    while(!stk.empty()){
        int v=stk.top();
        stk.pop();
        if(!visited[v]){
            mark++;
            dfs2(v);
        }
    }
    return mark;
}

int main(){
    while(scanf("%d%d",&n,&m)&&(m+n)){
        clean();
        cin.ignore();
        for(int i=1; i<=n; i++){
            string a;
            getline(cin,a);
            my[a]=i;
        }
        //cin.ignore();
        for(int i=0; i<m; i++){
            string a,b;
            getline(cin,a);
            getline(cin,b);
            int u=my[a];
            int v=my[b];
            graph[u].push_back(v);
            rev[v].push_back(u);
        }
        int res=Find_SCC();
        printf("%d\n",res);
    }
    return 0;
}
