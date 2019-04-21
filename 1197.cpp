#include "bits/stdc++.h"
using namespace std;

int parent[30010],Rank[30010];
int n,m;

void Build(){
    for(int i=0; i<=n; i++){
        Rank[i]=0;
        parent[i]=i;
    }
}

int Find(int x){
    if(x==parent[x])return x;
    return parent[x]=Find(parent[x]);
}

void Union(int a,int b){
    int U=Find(a);
    int V=Find(b);
    if(Rank[U]>Rank[V]){
        parent[V]=U;
    }
    else{
        parent[U]=V;
    }
    if(Rank[U]==Rank[V])Rank[V]+=1;
}

bool same(int u,int v){
    return Find(u)==Find(v);
}

int main(){
    while(scanf("%d %d",&n,&m) && (n+m)){
        Build();
        for(int i=1; i<=m; i++){
            int num;
            scanf("%d",&num);
            int u,v;
            for(int j=1; j<=num; j++){
            	scanf("%d",&v);
            	if(j==1)u=v;
            	else Union(u,v);
			}
        }
        int parofzero=Find(0);
        int cntt=0;
        for(int i=0; i<n; i++){
        	if(Find(i)==parofzero)cntt++;
		}
        printf("%d\n",cntt);
    }
    return 0;
}


