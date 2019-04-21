/**Algorithm Used: Kosaraju’s algorithm for strongly connected components**/

#include <bits/stdc++.h>
using namespace std;

map<string,int>my;
map<int,string>str;
vector<int>graph[27];
vector<int>rev[27];
vector<int>connected[27];
stack<int>stk;
bool visited[27];
int color[27];
int n,m;
int mark=0;

void clean(){
    for(int i=0; i<27; i++){
        graph[i].clear();
        rev[i].clear();
        connected[i].clear();
    }
    memset(visited,0,sizeof(visited));
    memset(color,0,sizeof(color));
    stk.empty();
    my.clear();
    str.clear();
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

void Find_SCC(){
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
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cs=1;
    bool ok=false;
    while(scanf("%d%d",&n,&m)==2&&(n+m)){
        clean();
        if(ok){
            printf("\n");
        }
        ok=true;
        int ind=1;
        for(int i=0; i<m; i++){
            string u,v;
            cin>>u>>v;
            if(!my[u]){
                my[u]=ind++;
                str[my[u]]=u;
            }
            if(!my[v]){
                my[v]=ind++;
                str[my[v]]=v;
            }
            graph[my[u]].push_back(my[v]);
            rev[my[v]].push_back(my[u]);
        }
        Find_SCC();
        printf("Calling circles for data set %d:\n",cs++);
        for(int i=1; i<=mark; i++){
            int sz=connected[i].size();
            for(int j=0; j<sz; j++){
                int f=connected[i][j];
                cout<<str[f];
                if(j<sz-1){
                    printf(", ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
