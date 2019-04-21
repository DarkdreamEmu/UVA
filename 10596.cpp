#include <bits/stdc++.h>
using namespace std;

#define mx 220

vector<int>graph[mx];
bool visited[mx];
int degree[mx];

void dfs(int s){
    visited[s]=1;
    int sz=graph[s].size();
    for(int i=0; i<sz; i++){
        int v=graph[s][i];
        if(!visited[v]){
            dfs(v);
        }
    }
}


int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        bool ok=false;
        if(m==0){
        	printf("Not Possible\n");
        	continue;
		}
        memset(degree,0,sizeof(degree));
        for(int i=0; i<m; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
       int cnt=0;
       memset(visited,0,sizeof(visited));
       for(int i=0; i<n; i++){
            if(!visited[i]&&degree[i]){
                dfs(i);
                cnt++;
            }
            if(cnt>1){
                break;
            }
        }
        if(cnt>1){
            printf("Not Possible\n");
        }
        else{
            bool take=true;
           for(int i=0; i<n; i++){
                if(degree[i]%2==0||degree[i]==0){
                    continue;
                }
                else{
                    take=false;
                    break;
                }
            }
            if(take){
                printf("Possible\n");
           }
            else{
                printf("Not Possible\n");
            }
        }
        for(int i=0; i<=n; i++){
        	graph[i].clear();
		}
    }
    return 0;
}
