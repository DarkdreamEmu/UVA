#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

#define mx 100000

vector<int>adj[mx];
int vsi[mx];
int c;
void bfs(int s)
{
    vsi[s]=1;
    c++;
    int p=adj[s].size();
    for(int i=0; i<p; i++)
    {
        if(vsi[adj[s][i]]==0)
        {
            bfs(adj[s][i]);
        }
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        memset(vsi,0,sizeof(vsi));
        int mox=0;
        for(int i=0; i<n; i++)
        {
            if(vsi[i]==0)
            {
                c=0;
                bfs(i);
                mox=max(mox,c);
            }
        }
        printf("%d\n",mox);
        for(int i=0; i<n; i++)adj[i].clear();
    }
    return 0;
}
