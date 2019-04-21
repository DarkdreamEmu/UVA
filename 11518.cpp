#include <bits/stdc++.h>
using namespace std;

#define mx 50000
vector<int>graph[mx];
bool visited[mx];
int cnt;

int dfs(int s)
{
    visited[s]=1;
    cnt++;
    for(int i=0; i<graph[s].size(); i++)
    {
        int v=graph[s][i];
        if(!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,l;
        cin>>n>>m>>l;
        memset(visited,0,sizeof(visited));
        memset(graph,0,sizeof(graph));

        cnt=0;
        for(int i=0; i<m; i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
        }
        while(l--)
        {
            int q;
            cin>>q;
            if(!visited[q])
            {
                dfs(q);
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
