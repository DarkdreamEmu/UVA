#include <bits/stdc++.h>
using namespace std;

#define edge pair<int,int>
#define mx 1000005

vector<pair<int, edge> >graph,mst;
int parent[mx],total=0;
int cnt=0;

int findset(int x, int *parent)
{
    if(x!=parent[x])
    {
        parent[x]=findset(parent[x],parent);
    }
    return parent[x];
}

void krushkal(int e)
{
    int i,pu,pv;
    sort(graph.begin(), graph.end()); //increasing order//
    total=0;
    for(int i=0; i<e; i++)
    {
        pu=findset(graph[i].second.first,parent);
        pv=findset(graph[i].second.second,parent);
        if(pu!=pv)
        {
            total=max(total,graph[i].first);
            cnt++;
            parent[pu]=parent[pv];
        }
    }
}
void reset(int n)
{
    //reset appropriate variable from here
    //like graph.clear(),mst.clear();

    for(int i=0; i<n; i++)parent[i]=i;
}

int main(){
    int v,e;
    while(scanf("%d%d",&v,&e)&&(v+e)){
        reset(v);
        for(int i=0; i<e; i++){
            long long int u,v,cos;
            scanf("%lld%d%d",&u,&v,&cos);
            graph.push_back(pair<int, edge>(cos,edge(u,v)));
        }
        krushkal(e);
        if(cnt==v-1){
            printf("%d\n",total);
        }
        else{
            printf("IMPOSSIBLE\n");
        }
        graph.clear();
        cnt=0;
    }
    return 0;
}
