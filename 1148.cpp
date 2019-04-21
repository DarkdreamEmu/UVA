#include <bits/stdc++.h>
using namespace std;

vector<int>adj[100000];
int dst[100000];
int c1,c2,nln,t;

int bfs(int s)
{

    queue<int>Q;
    Q.push(s);
    dst[s]=0;

    while(!Q.empty())
    {
        int u=Q.front();
        int t=dst[u];
        Q.pop();

        if(u==c2)
        {
            printf("%d %d %d\n",c1,c2,dst[u]-1);
            break;
        }

        for(int i=0; i<adj[u].size(); i++)
        {
             if (adj[u][i] != c1 && !dst[adj[u][i]])
            {
                dst[adj[u][i]]=t+1;
                Q.push(adj[u][i]);
            }
        }

    }
    if(t)
    {
        printf("\n");
    }
}

int main()
{
    nln=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(dst,0,sizeof(dst));
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
        }
        while(n--)
        {
            int u,k;
            scanf("%d%d",&u,&k);
            while(k--)
            {
                int v;
                scanf("%d",&v);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        scanf("%d%d",&c1,&c2);
        bfs(c1);
    }
    return 0;
}
