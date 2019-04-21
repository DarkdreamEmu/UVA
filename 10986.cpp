#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <assert.h>
#include <time.h>
#include <fstream>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long int li;
typedef long long int lli;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef pair<string,string> PSS;
typedef pair<int,string> PIS;
typedef map<int,int> Mapii;
typedef map<string,string> Mapss;
typedef map<string,int> Mapsi;
typedef map<int,string> Mapis;
typedef map<vector<int>,int > Mapvi;
typedef queue<int> qi;
typedef queue<long>ql;
typedef queue<long long>qll;

const int INF = 1000000000;
const int MAX = 4007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;


#define si(x) scanf("%d", &x)
#define sii(x, y) scanf("%d %d", &x, &y)
#define siii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define siv(x, y, z, a) scanf("%d %d %d %d", &x, &y, &z, &a)

#define pi(x) printf("%d\n", x)
#define pii(x, y) printf("%d %d\n", x, y)
#define piii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pkas(x) printf("Case %d:\n", x)
#define pkv(x, y) printf("Case %d: %d\n", x, y)

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))


int chToIn(char a){int b;b = a-'0';return b;}
int stToIn(string a){int b;b=atoi(a.c_str());return b;}
string appendChar(string s,char a){s.append(1,a);return s;}
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }



#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};

//int fx[]={1,-1,0,0};
//.int fy[]={0,0,1,-1};
VI edges[50001];
VI cost[50001];
int dis[50001];
bool visited[50001];

void dijkstra(int s)
{
    qi q;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        int siz=edges[tmp].size();
        FOR(i,0,siz)
        {
            if(dis[tmp] + cost[tmp][i]< dis[edges[tmp][i]])
            {
                dis[edges[tmp][i]]= dis[tmp] + cost[tmp][i];
                q.push(edges[tmp][i]);
            }
        }
    }
    return;
}

void clean()
{
    FOR(i,0,50001)
    {
        dis[i]=INF;
        cost[i].clear();
        edges[i].clear();
    }
}

int main()
{
    int t;
    si(t);
    int test=1;
    while(t--)
    {
        clean();
        int n,m,s,t;
        siv(n,m,s,t);
        FOR(i,0,m)
        {
            int u,v,w;
            siii(u,v,w);
            edges[u].PB(v);
            edges[v].PB(u);
            cost[u].PB(w);
            cost[v].PB(w);
        }
        if(m)
        {
            dijkstra(s);
        }
        if(dis[t]>=INF)
        {
            printf("Case #%d: unreachable\n",test++);
        }
        else
        {
            printf("Case #%d: %d\n",test++,dis[t]);
        }
    }
    return 0;
}
