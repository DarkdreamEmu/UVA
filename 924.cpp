#include <bits/stdc++.h>
using namespace std;

vector<int>adj[3000];
int visited[3000];
int dst[3000];
int result[3000];
int day,mx;

int bfs(int s)
{
    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    dst[s]=1;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                dst[v]=dst[u]+1;
                result[dst[u]]++;
                Q.push(v);
            }
        }
        if(result[dst[u]]>mx)
        {
            mx=result[dst[u]];
            day=dst[u];
        }
    }
}

int main()
{
    int e;
    while(scanf("%d",&e)==1)
    {
        for(int i=0; i<e; i++)
        {
            int n;
            scanf("%d",&n);
            for(int j=0; j<n; j++)
            {
                int a;
                scanf("%d",&a);
                adj[i].push_back(a);
            }
        }
        int test;
        scanf("%d",&test);
        for(int i=0; i<test; i++)
        {
            memset(visited,0,sizeof(visited));
            memset(dst,0,sizeof(dst));
            memset(result,0,sizeof(result));
            mx=0,day=0;
            int source;
            scanf("%d",&source);
            bfs(source);
            if(mx==0)
            {
                printf("0\n");
            }
            else
            {
                printf("%d %d\n",mx,day);
            }
        }
    }
    return 0;
}
