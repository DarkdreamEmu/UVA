#include <bits/stdc++.h>
using namespace std;

#define mx 10000
#define INF 999999999
vector<int>graph[mx];
int visited[mx];
int result[mx];

int bfs(int s)
{
    queue<int>q;
    q.push(s);
    result[s]=0;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        int siz=graph[top].size();
        for(int i=0; i<siz; i++)
        {
            int v=graph[top][i];
            if(result[v]==INF)
            {
                result[v]=result[top]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num,cup;
        cin>>num>>cup;
        for(int i=0; i<num; i++)
        {
            graph[i].clear();
            result[i]=INF;
        }
        for(int i=0; i<cup; i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bfs(0);
        for(int i=1; i<num; i++)
        {
            cout<<result[i]<<endl;
        }
        if(t)
        {
            printf("\n");
        }
    }
    return 0;
}
