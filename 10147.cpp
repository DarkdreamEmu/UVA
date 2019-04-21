#include <bits/stdc++.h>
using namespace std;

#define mx 770

#define pii pair<int,int>
vector<pii>res;
int parent[mx];
int matrix[mx][mx];
int xx[mx];
int yy[mx];
vector<pair<double, pii> >graph;
int cnt=0,e=0;

double dis(int a,int b){
    double x=(xx[a]-xx[b])*(xx[a]-xx[b]);
    double y=(yy[a]-yy[b])*(yy[a]-yy[b]);
    return sqrt(x+y);
}

int f_p(int x,int *parent){
    if(x!=parent[x]){
        parent[x]=f_p(parent[x],parent);
    }
    return parent[x];
}

void reset(int n){
    for(int i=1; i<=n; i++){
        parent[i]=i;
    }
}

void MST_kruskal(int e,int n){
    int uu,vv;
    sort(graph.begin(),graph.end());
    for(int i=0; i<e; i++){
        uu=f_p(graph[i].second.first,parent);
        vv=f_p(graph[i].second.second,parent);
        if(uu!=vv){
            parent[uu]=parent[vv];
            res.push_back(make_pair(graph[i].second.first,graph[i].second.second));
            cnt++;
        }
    }
}

void pri_res(int m){
    int sz=res.size();
    sort(res.begin(),res.end());
    for(int i=0; i<sz; i++){
        printf("%d %d\n",res[i].first,res[i].second);
    }
}

int main(){
    int t;
    bool ok=false;
    scanf("%d",&t);
    while(t--){

        if(ok){
            printf("\n");
        }
        ok=true;

        int n;
        scanf("%d",&n);
        reset(n);
        for(int i=1; i<=n; i++){
            scanf("%d%d",&xx[i],&yy[i]);
        }
        int m;
        scanf("%d",&m);
        for(int i=0; i<m; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            int mm=f_p(u,parent);
            int nn=f_p(v,parent);
            if(mm!=nn){
                parent[mm]=parent[nn];
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                if(f_p(i,parent)!=f_p(j,parent)){
                     double cos=dis(i,j);
                     graph.push_back(pair<double, pii>(cos,pii(i,j)));
                     e++;
                }
            }
        }
        MST_kruskal(e,n);
        if(!cnt){
            printf("No new highways need\n");
        }
        else{
            pri_res(m);
        }
        e=0;
        cnt=0;
        res.clear();
        graph.clear();
    }
    return 0;
}
