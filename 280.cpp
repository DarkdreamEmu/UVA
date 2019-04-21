#include <bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
bool visited[1000];


int dfs(int u)
{
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(visited[v]==false)
        {
            visited[v]=true;
            dfs(v);
        }
    }
}

int main()
{
    int ver,c,j;
    vector<int>res;
    while(scanf("%d",&ver)==1&&ver!=0)
    {
        for(int i=1; i<=ver; i++)adj[i].clear();
        int a;
        while(scanf("%d",&a)&&a!=0)
        {
            int b;
            while(scanf("%d",&b)==1&&b!=0)
            {
                adj[a].push_back(b);
            }
        }
        int test,start;
        scanf("%d",&test);
        while(test--)
        {
            memset(visited,false,sizeof(visited));

            scanf("%d",&start);
            dfs(start);

            for(int c=1; c<=ver; c++)
            {
                if(visited[c]==false)
                {
                    res.push_back(c);
                }
            }
            cout<<res.size();
            for(j=0; j<res.size(); j++)
            {
                if(j==0)cout<<" ";
                cout<<res[j];
                if(j<res.size()-1)cout<<" ";
            }
            printf("\n");
            res.clear();
        }
    }
    return 0;
}
