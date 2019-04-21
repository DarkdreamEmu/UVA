#include <bits/stdc++.h>
using namespace std;

#define edge pair<int,int>
#define mx 1000001

vector<pair<int, edge> >graph;
int parent[mx],total,n,e;

int findset(int x, int *parent)
{
    if(x!=parent[x])
    {
        parent[x]=findset(parent[x],parent);
    }
    return parent[x];
}

int krushkal(int m)
{
    int i,pu,pv;
    sort(graph.begin(), graph.end()); //increasing order//
    total=0;
    for(int i=0; i<m; i++)
    {
        pu=findset(graph[i].second.first,parent);
        pv=findset(graph[i].second.second,parent);
        if(pu!=pv)
        {
            total+=graph[i].first;
            parent[pu]=parent[pv];
        }
    }
    return total;
}
void reset(int n)
{
    for(int i=1; i<=n; i++)parent[i]=i;
}

int main(){
    int n;
    bool ok=false;
    while(scanf("%d",&n)==1){
        if(ok){
            printf("\n");
        }
        ok=true;
        reset(n);
        int tot=0;
        for(int i=0; i<n-1; i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            tot+=w;
        }
        int t;
        scanf("%d",&t);
        for(int i=0; i<t; i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            graph.push_back(pair<int, edge>(w,edge(u,v)));
        }
        int e;
        scanf("%d",&e);
        for(int i=0; i<e; i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            graph.push_back(pair<int, edge>(w,edge(u,v)));
        }
        int ll=e+t;
        int res=krushkal(ll);
        printf("%d\n%d\n",tot,res);
        graph.clear();

    }
    return 0;
}
