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


int chToIn(char a)
{
    int b;
    b = a-'0';
    return b;
}
int stToIn(string a)
{
    int b;
    b=atoi(a.c_str());
    return b;
}
string appendChar(string s,char a)
{
    s.append(1,a);
    return s;
}
int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
int lcm(int a, int b)
{
    return (a * (b / gcd(a, b)));
}



#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

int fx[] = {0,0,1,-1,1,1,-1,-1};
int fy[] = {1,-1,0,0,1,-1,1,-1};

string s[2000];
string tmp[2000];
int res[2000][2000];
bool vis[2000][2000];
int siz;
int n,num;
char ch;

int valid(int i,int j)
{
    return (i>=0&&i<n&&j>=0&&j<siz);
}

void dfs(int i,int j)
{
    res[i][j]=num;
    vis[i][j]=1;
    FOR(k,0,8)
    {
        int R=i+fx[k];
        int C=j+fy[k];
        if(valid(R,C)&&tmp[R][C]==ch&&!vis[R][C])
        {
            dfs(R,C);
        }
    }
}

int main()
{
    n=0;
    FILL(vis,0);
    //read("input.txt");
    //write("output.txt");
    while(true)
    {
        getline(cin,s[n]);
        if(feof(stdin) || s[n][0]=='%')
        {
            num=0;
            siz=tmp[0].size();
            FOR(i,0,n)
            {
                FOR(j,0,siz)
                {
                    if(!vis[i][j])
                    {
                        num++;
                        ch=tmp[i][j];
                        dfs(i,j);
                    }
                }
            }
            VI v;
            int j=0;
            while(j<siz)
            {
                int mx=1;
                FOR(i,0,n)
                {
                    mx=max(mx,res[i][j]);
                }
                int a=mx;
                stringstream ss;
                ss << a;
                string str = ss.str();
                int sizz=str.size();
                v.push_back(sizz);
                j++;
            }
            FOR(i,0,n)
            {
                FOR(j,0,siz)
                {
                    int m=v[j];
                    int b = res[i][j];
                    stringstream sss;
                    sss << b;
                    string str = sss.str();
                    int sizz=str.size();
                    FOR(k,sizz,m)
                    {
                        printf("%c",' ');
                    }
                    printf("%d",res[i][j]);
                    if(j<siz-1)
                    {
                        printf("%c",' ');
                    }
                }
                printf("\n");
            }
            printf("%c%c",'%','\n');
            num=0;
            FILL(vis,0);
            n=0;
            v.clear();
            if(feof(stdin))break;
        }
        else
        {
            int l=s[n].size();
            string tm="";
            FOR(j,0,l)
            {
                if(s[n][j]!=' ')
                {
                    tm+=(s[n][j]);
                }
            }
            tmp[n]=tm;
            n++;
        }
    }
    return 0;
}
