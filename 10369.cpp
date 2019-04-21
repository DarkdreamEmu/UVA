#include <bits/stdc++.h>
using namespace std;

#define mx 550
#define pii pair<int,int>
int parent[mx];
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
    for(int i=0; i<n; i++){
        parent[i]=i;
    }
}

double MST_kruskal(int e,int n){
    int uu,vv;
    double mn=0.0;
    sort(graph.begin(),graph.end());
    for(int i=0; i<e; i++){
        uu=f_p(graph[i].second.first,parent);
        vv=f_p(graph[i].second.second,parent);
        if(uu!=vv){
            parent[uu]=parent[vv];
            mn=max(graph[i].first,mn);
            cnt++;
            if(cnt==n){
                break;
            }
        }
    }
    return mn;
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int s,p;
        scanf("%d%d",&s,&p);
        for(int i=0; i<p; i++){
            scanf("%d%d",&xx[i],&yy[i]);
        }
        graph.clear();
        for(int i=0; i<p; i++){
            for(int j=i+1; j<p; j++){
                double cos=dis(i,j);
                graph.push_back(pair<double, pii>(cos,pii(i,j)));
                e++;
            }
        }
        reset(p);
        double res=MST_kruskal(e,(p-s));
        printf("%.2f\n",res);
        e=0;
        cnt=0;
        graph.clear();
    }
    return 0;
}
/*1
2 4
0 100
0 300
0 600
150 750
*/
