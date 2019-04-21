#include <bits/stdc++.h>
using namespace std;

const int mx=100;
#define pii pair<int,int>
#define pcc pair<char,char>
vector<pair<int, pii> >graph;
vector<pair<int, pii> >res;
int parent[mx];
int edges;

void reset(int n){
    for(int i=0; i<n; i++)parent[i]=i;
}

int fnd_p(int x,int *parent){
    if(parent[x]!=x){
        parent[x]=fnd_p(parent[x],parent);
    }
    return parent[x];
}

void MST_kruskal(int n){
    int u,v,cnt=0;
    sort(graph.begin(),graph.end());
    for(int i=0; i<graph.size(); i++){
        u=fnd_p(graph[i].second.second,parent);
        v=fnd_p(graph[i].second.first,parent);
        if(u!=v){
            parent[u]=parent[v];
            res.push_back(pair<int, pii>(graph[i].first,pii(graph[i].second.first,graph[i].second.second)));
            cnt++;
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&edges);
        int n=0;
        for(int i=0; i<edges; i++){
            int k=0;
            for(int j=0; j<edges; j++){
                int cost;
                scanf("%d, ",&cost);
                if(cost!=0&&n<k){
                    graph.push_back(pair<int, pii>(cost,pii(n,k)));
                }
                k++;
            }
          n++;
        }
        reset(n);
        MST_kruskal(n);
        printf("Case %d:\n",cs++);
        for(int i=0; i<res.size(); i++){
            printf("%c-%c %d\n",res[i].second.first+'A',res[i].second.second+'A',res[i].first);
        }
        res.clear();
        graph.clear();
    }
    return 0;
}
