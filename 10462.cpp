#include <bits/stdc++.h>
using namespace std;

const int MAX=110;
#define pii pair<int,int>

vector<pair <int,pii> >graph;
int parent[MAX];
map<int,int>flag;
int c=0;

void reset(int n){
    for(int i=1; i<=n; i++)parent[i]=i;
}

int f_p(int x,int *parent){
    if(x!=parent[x]){
        parent[x]=f_p(parent[x],parent);
    }
    return parent[x];
}

int MST_kruskal_1(int e){
    int pu,pv,total=0,ff=0;
    sort(graph.begin(),graph.end());
    for(int i=0; i<e; i++){
        pu=f_p(graph[i].second.first,parent);
        pv=f_p(graph[i].second.second,parent);
        if(pu!=pv){
            parent[pu]=parent[pv];
            total+=graph[i].first;
            flag[ff++]=i;
            c++;
        }
    }
    return total;
}

int MST_kruskal_2(int e,int n){
    int pu,pv,mn=10000000,sum=0,cnt;
    for(int i=0; i<n; i++){
        reset(n);
        sum=0;
        cnt=0;
        for(int j=0; j<e&&cnt<n-1; j++){
            if(flag[i]!=j){
                pu=f_p(graph[j].second.first,parent);
                pv=f_p(graph[j].second.second,parent);
                if(pu!=pv){
                    parent[pu]=parent[pv];
                    sum+=graph[j].first;
                    cnt++;
                }
            }
        }
        if(cnt==n-1&&mn>sum){
            mn=sum;
        }
    }
    return mn;
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int v,e;
        scanf("%d%d",&v,&e);
        reset(v);
        for(int i=0; i<e; i++){
            int v1,v2,cos;
            scanf("%d%d%d",&v1,&v2,&cos);
            graph.push_back(pair<int,pii>(cos,pii(v1,v2)));
        }
        int res1=MST_kruskal_1(e);
        int res2=MST_kruskal_2(e,v);

        printf("Case #%d : ",cs++);
        if(c==v-1){
            if((res2!=10000000)&&e!=0){
                printf("%d\n",res2);
            }
            else{
                printf("No second way\n");
            }
        }
        else{
            printf("No way\n");
        }
        graph.clear();
        flag.clear();
        c=0;
    }
    return 0;
}
