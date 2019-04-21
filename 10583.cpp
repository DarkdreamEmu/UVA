#include <stdio.h>
#include <iostream>
#include <math.h>
#include <map>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define mx 500001

vector<int>graph[mx];
int visited[mx];

void bfs(int s)
{

    queue<int>Q;
    Q.push(s);
    visited[s]=1;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        int l=graph[u].size();
        for(int i=0; i<l; i++)
        {
            if(visited[graph[u][i]]==0)
            {
                int v=graph[u][i];
                visited[v]=1;
                Q.push(v);
            }
        }
    }

}

int main()
{
    int n,m;
    int test=1;
    while(scanf("%d%d",&n,&m)==2&&n!=0&&m!=0)
    {
        memset(graph,NULL,sizeof(graph));
        memset(visited,0,sizeof(visited));
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int count=0;
        for(int i=1; i<=n; i++)
        {
            if(visited[i]==0)
            {
                bfs(i);
                count++;
            }
        }
        printf("Case %d: %d\n",test++,count);
    }
    return 0;
}
