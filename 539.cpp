#include <bits/stdc++.h>
using namespace std;

vector<int>graph[30];
int visited[30][30];
int best;

int dfs(int s){
	int cnt=0;
	for(int i=0; i<graph[s].size(); i++){
		int v=graph[s][i];
		if(!visited[s][v]){
			visited[s][v]=visited[v][s]=1;
			cnt=max(cnt,1+dfs(v));
			visited[s][v]=visited[v][s]=0;
		}
	}
	return cnt;
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)&&(n+m)){
        for(int i=0; i<m; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        best=0;
        for(int i=0; i<n; i++){
            memset(visited,0,sizeof(visited));
            best=max(best,dfs(i));
        }
        printf("%d\n",best);
        for(int i=0; i<=n; i++){
        	graph[i].clear();
		}
    }
    return 0;
}
