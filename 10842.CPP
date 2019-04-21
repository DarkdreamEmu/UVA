#include <bits/stdc++.h>
using namespace std;

struct node{
    int u,v,cos;
}my[11111];

int parent[11111];

int findset(int x){
    if(parent[x]==x)return x;
    else return parent[x]=findset(parent[x]);
}

bool cmp(node a,node b){
    return a.cos>b.cos;
}

int mst(int i,int m){
    int res;
    for(int j=0; j<i; j++){
        int u=findset(my[j].u);
        int v=findset(my[j].v);
        if(u!=v){
            parent[u]=v;
            res=my[j].cos;
        }
        if(m==1){
            res=my[j].cos;
            break;
        }
    }
    return res;
}

int main(){
    int t,ts=1;
    cin>>t;
    while(t--){
        int m,n,i;
        cin>>m>>n;
        for(i=0; i<=m; i++)parent[i]=i;
        for(i=0; i<n; i++){
            cin>>my[i].u>>my[i].v>>my[i].cos;
        }
        sort(my,my+i,cmp);
        int res=mst(i,m);
        printf("Case #%d: %d\n",ts++,res);
    }
    return 0;
}
