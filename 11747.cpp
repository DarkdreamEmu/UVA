#include <bits/stdc++.h>
using namespace std;

#define edge pair<long long,long long>
#define mx 1010
vector<long long>res;

vector<pair<long long, edge> >graph;
int parent[mx];
long long total=0;

int findset(int x, int *parent)
{
    if(x!=parent[x])
    {
        parent[x]=findset(parent[x],parent);
    }
    return parent[x];
}

void krushkal(long long n)
{
    long long i,pu,pv;
    sort(graph.begin(), graph.end());
    total=0;
    for(i=0; i<graph.size(); i++)
    {
        pu=findset(graph[i].second.first,parent);
        pv=findset(graph[i].second.second,parent);
        if(pu!=pv)
        {
            total+=graph[i].first;
            parent[pu]=parent[pv];
        }
        else{
            res.push_back(graph[i].first);
        }
    }
}
void reset(long long n)
{
    for(int i=0; i<=n; i++)parent[i]=i;
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
        krushkal(v);
        if(res.size()==0){
            printf("forest\n");
        }
        else{
            sort(res.begin(),res.end());
            for(int i=0; i<res.size(); i++){
                cout<<res[i];
                if(i!=res.size()-1){
                    printf(" ");
                }
            }
            printf("\n");
        }
        res.clear();
        graph.clear();
    }
    return 0;
}
