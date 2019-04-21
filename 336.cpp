#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define mx 100000
#define INF 999999999


int visited[mx];
int dst[mx];
vector<int>temp;

void bfs(int s,int tlt,map<int, vector<int> >adj)
{

    queue<int>Q;
    visited[s]=1;
    dst[s]=0;
    Q.push(s);

    temp.push_back(s);
    //int count=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        int l=adj[u].size();
        if(l==0)
        {
            temp.clear();
        }
        for(int i=0; i<l; i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                int v=adj[u][i];
                visited[v]=1;
                dst[v]=dst[u]+1;
                /*if(dst[v]>tlt)
                {
                    count++;
                }*/
                if(dst[v]<=tlt)
                {
                    temp.push_back(v);
                }
                Q.push(v);
            }
        }
    }

}

int main()
{
    int nc,test=1;
    while(scanf("%d",&nc)==1&&nc!=0)
    {
        map<int, vector<int> >adj;
        for(int i=0; i<nc; i++)
        {
            int a,c;
            scanf("%d%d",&a,&c);
            adj[a].push_back(c);
            adj[c].push_back(a);
        }
        int start,tlt;
        while(scanf("%d%d",&start,&tlt)==2)
        {
            if(start==0&&tlt==0)
            {
                break;
            }
            temp.clear();
            memset(visited,0,sizeof(visited));
            memset(dst,0,sizeof(dst));
            bfs(start,tlt,adj);

            //cout<<adj.size()<<" "<<temp.size()<<endl;
            int result;
            result=adj.size()-temp.size();
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",test++,result,start,tlt);
        }
        adj.empty();
        //printf("\n");
    }
    return 0;
}


