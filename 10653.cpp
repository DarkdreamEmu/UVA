/***************************************************DarkdreamOFmy**********************************************************/
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

typedef                                     long int li;
typedef                                     long long int lli;
typedef                                     unsigned long long int ull;
typedef                                     signed long long int sll;
typedef                                     long double lld;
typedef                                     vector<int>vi;
typedef                                     vector<long>vl;
typedef                                     vector<long long int>vll;
typedef                                     vector<double>vd;
typedef                                     vector<long double>vld;
typedef                                     vector<char>vc;
typedef                                     vector<string>vs;
typedef                                     pair<int,int>pii;
typedef                                     pair<long long,long long>pll;
typedef                                     pair<double,double>pdd;
typedef                                     pair<char,char>pcc;
typedef                                     pair<string,string>pss;
typedef                                     map<int,int>mii;
typedef                                     map<long long,long long>mll;
typedef                                     map<char,char>mcc;
typedef                                     map<string,string>mss;
typedef                                     map<string,int>msi;
typedef                                     map< int,vector<int> >miv;
typedef                                     map<vector<int>,vector<int> >mvvi;
typedef                                     map<string,vector<int> >msv;
typedef                                     set<int>si;
typedef                                     set<string>ss;
typedef                                     set<vector<int> >sv;
typedef                                     queue<int>qi;
typedef                                     queue<long long>qll;
typedef                                     queue<string>qs;
typedef                                     stack<int>stki;
typedef                                     stack<long long>stkll;

/**-------------------END OF typedef------------------------------**/


const int                                   INF  = 1000000000;
const int                                   MAX  = 4007;
const int                                   MAX2 = 1001;
const int                                   MAXD = 20;
const int                                   BASE = 1000000007;
const int                                   MOD  = 1000000007;
const int                                   psz  = 2000006;


/**-------------------Constant int--------------------------------**/

#define scanI(a)                            scanf("%d",&a)
#define scanI2(a,b)                         scanI(a) , scanI(b)
#define scanI3(a,b,c)                       scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d)                     scanI(a), scanI(b), scanI(c), scanI(d)

#define scanL(a)                            scanf("%lld",&a)
#define scanL2(a,b)                         scanL(a) , scanL(b)
#define scanL3(a,b,c)                       scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d)                     scanL(a), scanL(b), scanL(c), scanL(d)

#define printI(a)                           printf("%d",a)
#define printI2(a,b)                        printI(a) , printI(b)
#define printI3(a,b,c)                      printI(a),printI(b),printI(c)
#define printI4(a,b,c,d)                    printI(a),printI(b),printI(c),printI(d)

#define printL(a)                           printf("%lld",a)
#define printL2(a,b)                        printL(a) , printL(b)
#define printL3(a,b,c)                      printL(a),printL(b),printL(c)
#define printL4(a,b,c,d)                    printL(a),printL(b),printL(c),printL(d)

/**----------------------Scan and print end--------------------------**/

#define min3(a,b,c)                         min(a,min(b,c))
#define max3(a,b,c)                         max(a,max(b,c))
#define min4(a,b,c,d)                       min(min(a,b),min(c,d))
#define max4(a,b,c,d)                       max(max(a,b),max(c,d))
#define max5(a,b,c,d,e)                     max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e)                     min(min3(a,b,c),min(d,e))

/**----------------------MAX and MIN end-----------------------------**/

#define fst                                 first
#define snd                                 second
#define all(a)                              a.begin(),a.end()
#define rall(a)                             a.rbegin(),a.rend()
#define SQR(a)                              ((a)*(a))
#define Unique(a)                           sort(all(a)),a.erase(unique(all(a)),a.end())
#define Iterator(a)                         __typeof__(a.begin())
#define rIterator(a)                        __typeof__(a.rbegin())
#define FORI(a,it)                           for(Iterator(a) it = a.begin();it != a.end(); it++)
#define RFORI(a,it)                          for(rIterator(a) it = a.rbegin();it != a.rend(); it++)
#define FOR(i, a, b)                        for(int i=(a);i<(b);i++)
#define RFOR(i, b, a)                       for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value)                       memset(A,value,sizeof(A))
#define SZ(V)                               (int)V.size()
#define PB                                  push_back
#define MP                                  make_pair
#define Pi                                  3.14159265358979
#define read(x)                             freopen(x, "r", stdin)
#define write(x)                            freopen(x, "w", stdout)

/**---------------------End of define of all----------------------**/


int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

/**-----------------------Directional------------------------------**/

int chToIn(char a)                          {int b;b = a-'0';return b;}
int stToIn(string a)                        {int b;b=atoi(a.c_str());return b;}
string appendChar(string s,char a)          {s.append(1,a);return s;}
int gcd(int a, int b)                       {return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b)                       {return (a * (b / gcd(a, b))); }
string rev(string a)                        {int siz=SZ(a);string res="";RFOR(i,siz,0){res+=a[i];}return res;}

/**---------------------End of functions--------------------------**/

int cost[MAX2][MAX2];
int visited[MAX2][MAX2];
int graph[MAX2][MAX2];
int m,n;

void bfs(int s,int d){
    qi q;
    visited[s][d]=1;
    q.push(s);
    q.push(d);
    cost[s][d]=0;
    while(!q.empty()){
        int R,C,x,y;
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        FOR(i,0,4){
            R=dx[i]+x;
            C=dy[i]+y;
            if((R>=0&&R<m)&&(C>=0&&C<n)&&!visited[R][C]&&!cost[R][C]&&!graph[R][C]){
                q.push(R);
                q.push(C);
                visited[R][C]=1;
                cost[R][C]=cost[x][y]+1;
            }
        }
    }
}



int main(){
    while(scanI2(m,n)&&(m+n)){
        FILL(visited,0);
        FILL(cost,0);
        FILL(graph,0);
        int r;
        scanI(r);
        FOR(i,0,r){
            int k,num;
            scanI2(k,num);
            FOR(j,0,num){
                int a;
                scanI(a);
                graph[k][a]=1;
            }
        }
        int s,d;
        scanI2(s,d);
        bfs(s,d);
        int l,l1;
        scanI2(l,l1);
        printf("%d\n",cost[l][l1]);
    }
    return 0;
}
