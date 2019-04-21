#include <bits/stdc++.h>
using namespace std;

#define mx 1110
#define pii pair<int,int>
int parent[mx];
int xx[mx];
int yy[mx];
int matrix[mx][mx];
vector<pair<double, pii> >graph;
int cnt=0,e=0,p=0,stat=1;
double rail=0,road=0;

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
    for(int i=0; i<n; i++){
        parent[i]=i;
    }
}

void MST_kruskal(int e,int w,int n){
    int uu,vv;
    sort(graph.begin(),graph.end());
    for(int i=0; i<e&&p<n-1; i++){
        uu=f_p(graph[i].second.first,parent);
        vv=f_p(graph[i].second.second,parent);
        if(uu!=vv){
            parent[uu]=parent[vv];
            p++;
            if(graph[i].first>w){
                rail+=graph[i].first;
                stat++;
            }
            else{
                road+=graph[i].first;
            }
        }
    }
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int m,w;
        scanf("%d%d",&m,&w);
        for(int i=0; i<m; i++){
            scanf("%d%d",&xx[i],&yy[i]);
        }
        reset(m);
        for(int i=0; i<m; i++){
            for(int j=i+1; j<m; j++){
                double cos=dis(i,j);
                graph.push_back(pair<double, pii>(cos,pii(i,j)));
                e++;
            }
        }
        MST_kruskal(e,w,m);
        printf("Case #%d: %d %.f %.f\n",cs++,stat,road,rail);
        stat=1;
        road=0;
        rail=0;
        p=0;
        graph.clear();
    }
    return 0;
}
