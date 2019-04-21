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
typedef pair<int,int> PII;
typedef map<int,int> Mapii;
typedef map<string,string> Mapss;
typedef map<string,int> Mapsi;
typedef map<vector<int>,int > Mapvi;

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

#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};

//int fx[]={1,-1,0,0};
//int fy[]={0,0,1,-1};
int r;

char s[25][25];
char s1[25][25];
char res[25][25];

char check(int i,int j)
{
    int cnt=0;
    FOR(k,0,8)
    {
        int R=i+fx[k];
        int C=j+fy[k];
        if(R>=0&&R<r&&C>=0&&C<r)
        {
            if(s[R][C]=='*')
            {
              cnt++;
            }
        }
    }
    return (cnt+'0');
}

void check1(int n)
{
    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
            if(s[i][j]=='*')
            {
                res[i][j]='*';
            }
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    si(t);
    bool ok=false;
    while(t--)
    {
        if(ok)cout<<endl;
        ok=true;
        si(r);

        FOR(i,0,r)
        {
            cin>>s[i];
        }
        FOR(i,0,r)
        {
            cin>>s1[i];
        }

        FOR(i,0,r)
        {
            FOR(j,0,r)
            {
                res[i][j]='.';
            }
        }

        FOR(i,0,r)
        {
            FOR(j,0,r)
            {
                if(s[i][j]=='.'&&s1[i][j]=='x')
                {
                    res[i][j]=check(i,j);
                }
                if(s[i][j]=='*'&&s1[i][j]=='x')
                {
                    check1(r);
                }
            }
        }

        FOR(i,0,r)
        {
            FOR(j,0,r)
            {
                cout<<res[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
