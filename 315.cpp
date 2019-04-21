#include <bits/stdc++.h>
using namespace std;

const long MAX=107;
bool vis[MAX];
bool AP[MAX];
int parent[MAX];
int low[MAX];
int disc[MAX];
vector<int>graph[MAX];
int tim;

void intialization(){
    for(int i=0; i<MAX; i++){
        vis[i]=AP[i]=false;
        parent[i]=-1;
        low[i]=0;
        graph[i].clear();
    }
    tim=0;
}

void Articulation_point(int u){
    vis[u]=true;
    low[u]=disc[u]=++tim;
    int child=0;
    int sz=graph[u].size();
    for(int i=0; i<sz; i++){
        int v=graph[u][i];
        if(vis[v]==false){
            child++;
            parent[v]=u;
            Articulation_point(v);
            low[u]=min(low[u],low[v]);

            if((parent[u]!=-1)&&low[v]>=disc[u]){
                AP[u]=true;
            }
            if(parent[u]==-1&&child>1){
                AP[u]=true;
            }
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],disc[v]);
        }
    }
}

int main(){
    int n;
    while(scanf("%d",&n)&&n){
        intialization();
        int u;
        while(scanf("%d",&u)&&u){
            string s;
            getline(cin,s);
            stringstream ss(s);
            int v;
            while(ss>>v){
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        int cnt=0;
        Articulation_point(1);
        for(int i=1; i<=n; i++){
            if(AP[i]){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
