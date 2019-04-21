#include <bits/stdc++.h>
using namespace std;

#define mx 770
#define pii pair<int,int>
int parent[mx];
int xx[mx];
int yy[mx];
int matrix[mx][mx];
vector<pair<double, pii> >graph;
int cnt=0,e=0,p=0;

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

double MST_kruskal(int e,int n){
    int uu,vv;
    double sum=0.0;
    sort(graph.begin(),graph.end());
    for(int i=0; i<e&&p<n-1; i++){
        uu=f_p(graph[i].second.first,parent);
        vv=f_p(graph[i].second.second,parent);
        if(uu!=vv){
            parent[uu]=parent[vv];
            sum+=graph[i].first;
            p++;
        }
    }
    return sum;
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int m;
    while(scanf("%d",&m)==1){
        for(int i=0; i<m; i++){
            scanf("%d%d",&xx[i],&yy[i]);
        }
        graph.clear();
        int k;
        scanf("%d",&k);
        reset(m);
        for(int i=0; i<k; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            int mm=f_p(u-1,parent);
            int nn=f_p(v-1,parent);
            if(mm!=nn){
                parent[mm]=parent[nn];
                p++;
            }
        }
        for(int i=0; i<m; i++){
            for(int j=i+1; j<m; j++){
               double cos=dis(i,j);
                graph.push_back(pair<double, pii>(cos,pii(i,j)));
                e++;
            }
        }
        double res=MST_kruskal(e,m);
        printf("%0.2f\n",res);
        e=0;
        cnt=0;
        p=0;
        graph.clear();
    }
    return 0;
}
