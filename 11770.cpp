#include <bits/stdc++.h>
using namespace std;

const int mx=10010;
vector<int>graph[mx];
int visited[mx];
vector<int>store;

void dfs(int u){
    visited[u]=1;
    int sz=graph[u].size();
    for(int i=0; i<sz; i++){
        int v=graph[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
    store.push_back(u);
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n; i++){
            graph[i].clear();
        }
        for(int i=0; i<m; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            u--,v--;
            graph[u].push_back(v);
        }
        int cnt=0;
        store.clear();
        memset(visited,0,sizeof(visited));
        for(int i=0; i<n; i++){
            if(!visited[i]){
               dfs(i);
            }
        }
        memset(visited,0,sizeof(visited));

        reverse(store.begin(),store.end());
        for(int i=0; i<store.size(); i++){
            if(!visited[store[i]]){
                dfs(store[i]);
                cnt++;
            }
        }
        printf("Case %d: %d\n",cs++,cnt);
    }
    return 0;
}
