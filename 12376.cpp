#include <bits/stdc++.h>
using namespace std;

#define mxn 110

vector<int>graph[mxn];
int cost[mxn];
bool visited[mxn];
int sum=0;
int last=0;


void dfs(int u)
{
    int v;
    visited[u]=1;
    int mx=0,tmp=-1;
    for(int i=0; i<graph[u].size(); i++)
    {
        v=graph[u][i];
        if(!visited[v])
        {
            if(cost[v]>mx)
            {
                mx=cost[v];
                tmp=v;
            }
        }
    }

    if(tmp!=-1)
    {
        sum=sum+mx;
        last=tmp;
        dfs(tmp);
    }
    return;
}

int main()
{
    int n,e;
    int t,test=1;
    cin>>t;

    while(t--)
    {
        cin>>n>>e;
        for(int i=0; i<n; i++)
        {
            cin>>cost[i];
        }
        for(int i=0; i<e; i++)
        {
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
        }
        memset(visited,0,sizeof(visited));

        dfs(0);
        printf("Case %d: %d %d\n",test++,sum,last);

        for(int i=0; i<n; i++)
        {
            graph[i].clear();
        }

        sum=0;
        last=0;
    }
    return 0;
}
