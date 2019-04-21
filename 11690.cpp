#include <bits/stdc++.h>
using namespace std;

#define N 10011

int parent[N];
int Rank[N];
int money[N];

int find_root(int x) { return parent[x]==x ? x : (parent[x]=find_root(parent[x]));}
void Union(int x,int y){
    int x_root=find_root(x); int y_root=find_root(y); if(x_root==y_root)return ;
    if(Rank[x_root]<Rank[y_root]) parent[x_root]=y_root;
    else if(Rank[x_root]>Rank[y_root]) parent[y_root]=x_root;
    else {parent[y_root]=x_root; Rank[x_root]=Rank[x_root]+1;}
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++){
            scanf("%d",&money[i]);
            parent[i]=i;
        }
        int sum=0;
        for(int i=0; i<m; i++){
            int u,v;
            scanf("%d %d",&u,&v);
            if(find_root(u)!=find_root(v)){
                Union(u,v);
            }
        }
        set<long long>take[N];
        for(int i=0; i<n; i++){
            take[find_root(i)].insert(i);
        }
        set<long long>push;
        for(int i=0; i<n; i++){
            if(take[i].size()==0)continue;
            long long sum=0;
            set<long long>::iterator it=take[i].begin();
            while(it!=take[i].end()){
                sum+=money[*it];
                it++;
            }
            push.insert(sum);
        }
        if(push.size()==1)puts("POSSIBLE");
        else puts("IMPOSSIBLE");
        for(int i=0; i<N; i++){
            take[i].clear();
        }
        push.clear();
    }
    return 0;
}
