#include <bits/stdc++.h>
using namespace std;

vector<int>graph[22];
int vst[50];
int dst[50];

int bfs(int s,int d){
    queue<int>q;
    vst[s]=1;
    dst[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int sz=graph[u].size();
        for(int i=0; i<sz; i++){
            int v=graph[u][i];
            if(!vst[v]){
                vst[v]=1;
                dst[v]=dst[u]+1;
                q.push(v);
            }
        }
    }
    return dst[d];
}

int main(){
    int x,c=1;
    while(scanf("%d",&x)==1){
        for(int i=0; i<x; i++){
            int y;
            scanf("%d",&y);
            graph[1].push_back(y);
            graph[y].push_back(1);
        }
        for(int i=2; i<=19; i++){
            int num;
            scanf("%d",&num);
            for(int j=0; j<num; j++){
                int v;
                scanf("%d",&v);
                graph[i].push_back(v);
                graph[v].push_back(i);
            }
        }
        int q;
        scanf("%d",&q);
        printf("Test Set #%d\n",c++);
        while(q--){
            memset(vst,0,sizeof(vst));
            int src,des;
            scanf("%d%d",&src,&des);
            int res=bfs(src,des);
            printf("%2d to %2d: %d\n",src,des,res);
        }
        printf("\n");
        for(int i=0; i<22; i++){
            graph[i].clear();
        }
    }
    return 0;
}
