#include <bits/stdc++.h>
using namespace std;

/**Algorithm Use:Prim's MST
I count the number of visited city from starting city.If count same as the number of city the print minimum cost else impossible**/

map<string,int>my;
vector< pair<int,int> >adj[100010];
bool marked[100010];
typedef pair<long long,int>PII;
int cnt=0;

long long prim(int x)
{
    priority_queue< PII,vector<PII>,greater<PII> >Q;
    int y;
    long long mincost=0;
    PII p;
    Q.push(make_pair(0,x));
    while(!Q.empty())
    {
        p=Q.top();
        Q.pop();
        x=p.second;
        if(marked[x]==true)
        {
            continue;
        }
        mincost+=p.first;
        marked[x]=true;
        cnt++;
        for(int i=0; i<adj[x].size(); i++)
        {
            y=adj[x][i].second;
            if(marked[y]==false)
            {
                Q.push(adj[x][i]);
            }
        }
    }
    return mincost;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        memset(marked,0,sizeof(marked));
        for(int i=1; i<=n; i++)
        {
            char s[15];
            scanf("%s",s);
            my[s]=i;
        }
        for(int i=1; i<=m; i++)
        {
            char s[15],s1[15];
            scanf("%s%s",s,s1);
            int cost;
            scanf("%d",&cost);
            adj[my[s]].push_back(make_pair(cost,my[s1]));
            adj[my[s1]].push_back(make_pair(cost,my[s]));
        }
        char s[15];
        scanf("%s",s);
        long long res=prim(my[s]);
        if(cnt==n)
        {
            printf("%lld\n",res);
        }
        else
        {
            printf("Impossible\n");
        }
        for(int i=0; i<=405; i++)
        {
            adj[i].clear();
        }
        my.clear();
        cnt=0;
    }
    return 0;
}
