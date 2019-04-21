#include <bits/stdc++.h>
using namespace std;

#define edge pair<int,int>
#define mx 10011

vector<pair<int, edge> >graph;

vector<int>mst;

int parent[mx],w;

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
    for(int i=0; i<e&&graph[i].first<w; i++)
    {
        pu=findset(graph[i].second.first,parent);
        pv=findset(graph[i].second.second,parent);
        if(pu!=pv)
        {
            mst.push_back(graph[i].first);
            parent[pu]=parent[pv];
        }
    }
}
void reset(int n)
{
    for(int i=0; i<=n; i++)parent[i]=i;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        int m,n;
        scanf("%d%d%d",&n,&m,&w);
        reset(n);
        for(int i=0; i<m; i++){
            int u,v,cos;
            scanf("%d%d%d",&u,&v,&cos);
            graph.push_back(pair<int, edge>(cos,edge(u,v)));
        }
        krushkal(m);
        int sum=0;
        for(int i=0; i<mst.size(); i++){
            sum+=mst[i];
        }
        int cnt=0;
        for(int i=1; i<=n; i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        printf("Case #%d: %d %d\n",cas++,((cnt*w)+sum),cnt);
        mst.clear();
        graph.clear();
    }
    return 0;
}
