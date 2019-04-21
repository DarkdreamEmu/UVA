#include <bits/stdc++.h>
using namespace std;

map<string,int>my;

#define edge pair<long long,long long>
#define mx 5010

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
    sort(graph.begin(), graph.end()); //increasing order//
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
    }
}
void reset(long long n)
{
    for(int i=1; i<=n; i++)parent[i]=i;
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--){
        long long m,n;
        scanf("%lld%lld",&m,&n);
        reset(m);
        long long cnt=0;
        for(int i=1; i<=n; i++){
            string s1,s2;
            long long cost;
            cin>>s1>>s2>>cost;
            if(my.find(s1)==my.end()){
                my[s1]=++cnt;
            }
            if(my.find(s2)==my.end()){
                my[s2]=++cnt;
            }
            long long w=cost;
            long long u=my[s1];
            long long v=my[s2];
            graph.push_back(pair<long long, edge>(w,edge(u,v)));
        }
        krushkal(m);
        printf("%lld\n",total);
        graph.clear();
        my.clear();
        if(t){
            printf("\n");
        }
        total=0;
    }
    return 0;
}
