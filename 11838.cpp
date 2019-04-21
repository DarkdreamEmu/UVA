/**Algorithm Used: Kosaraju’s algorithm for strongly connected components**/

#include <bits/stdc++.h>
using namespace std;

const int mx=2010;

vector<int>graph[mx];
vector<int>rev[mx];
vector<int>connected[mx];
stack<int>stk;
int visited[mx];
int color[mx];
int mark=0;

void clean(int n){
    for(int i=1; i<=n; i++){
        graph[i].clear();
        rev[i].clear();
        connected[i].clear();
    }
    memset(visited,0,sizeof(visited));
    memset(color,0,sizeof(color));
    stk.empty();
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

int Find_SCC(int n){
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
    int n,m;
    while(scanf("%d%d",&n,&m)&&(n+m)){
        clean(n);
        for(int i=0; i<m; i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(w==1){
                graph[u].push_back(v);
                rev[v].push_back(u);
            }
            else{
                graph[u].push_back(v);
                graph[v].push_back(u);
                rev[v].push_back(u);
                rev[u].push_back(v);
            }
        }
        int res=Find_SCC(n);
       //cout<<mark<<endl;
        if(res==1){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
