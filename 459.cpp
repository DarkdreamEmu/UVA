#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//#define sf(x) scanf("%d",x)
//#define sf1(a,b) scanf("%c%c",&a,&b)
//#define sf3(x) scanf("%c",x)
#define mx 100000

vector<int>adj[mx];
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
        int l=adj[u].size();
        for(int i=0; i<l; i++)
        {
            if(visited[adj[u][i]]==0)
            {
                int v=adj[u][i];
                visited[v]=1;
                Q.push(v);
            }
        }
    }

}

int main()
{
    int t;
    char s[3];
    cin>>t;
    scanf("\n");
    while(t--)
    {
        gets(s);
        int m=s[0]-'A';
        memset(adj,0,sizeof(adj));
        memset(visited,0,sizeof(visited));
        while(gets(s)&&s[0])
        {
            int a,b;
            a=s[0]-'A';
            b=s[1]-'A';
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int count=0;
        for(int i=0; i<=m; i++)
        {
            if(visited[i]==0)
            {
                bfs(i);
                count++;
            }
        }
        printf("%d\n",count);

        if(t>0)
        {
            printf("\n");
        }
        for(int i=0; i<=m; i++)   adj[i].clear();
    }
    return 0;
}
