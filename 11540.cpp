#include <bits/stdc++.h>
using namespace std;

const int mx=100010;
vector<int>graph[mx];
vector<int>store;
bool color[mx];
int res=0;

void dfs(int u){
    color[u]=1;
    int sz=graph[u].size();
    for(int i=0; i<sz; i++){
        int v=graph[u][i];
        if(!color[v]){
            dfs(v);
        }
    }
    store.push_back(u);
}

int SCC(int n){
    res=0;
    memset(color,0,sizeof(color));
    for(int i=1; i<=n; i++){
        if(!color[i]){
            dfs(i);
        }
    }
    memset(color,0,sizeof(color));
    int sz=store.size();
    for(int i=sz-1; i>=0; i--){
        if(!color[store[i]]){
            res++;
            dfs(store[i]);
        }
    }
    return res;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }
        printf("%d\n",SCC(n));
        for(int i=0; i<=n; i++){
            graph[i].clear();
        }
        store.clear();
    }
    return 0;
}

