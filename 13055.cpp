
/***********************************************************\
                                                             |
                                                             |
 D̲a̲R̲K̲d̲r̲e̲a̲m̲E̲M̲U̲:::::::                             |
 Akrabul Islam Imran::::::::                                 |
 akrabulislam1@gmail.com::::::::                             |
 Uva-online:DarkdreamOfmY:::::::::                           |
                                                             |
                                                             |
 ............................Don't Quit,jUST do IT.......    |                                                     |
                                                             |
                                                             |
                                                             |
/***********************************************************/

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
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

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

#define sc(x) cin>>x
#define scc(x, y) cin>>x>>y
#define sccc(x, y, z) cin>>x>>y>>z
#define scccc(x, y, z, a) cin>>x>>y>>z>>a

#define pr(x) cout<<x<<endl;
#define prr(x, y) cout<<x<<" "<<y<<endl;
#define prrr(x, y, z) cout<<x<<" "<<y<<" "<<z<<endl;
#define prrrr(x, y, z, a) cout<<x<<" "<<y<<" "<<z<<" "<<a<<endl;
#define prrrrr(x, y, z, a, b) cout<<x<<" "<<y<<" "<<z<<" "<<a<<" "<<b<<endl;

#define deb(x) cout << #x << ": " << x << endl;
#define debb(x, y) cout << #x << ": " << x << " " << #y << ": " << y << endl;
#define debbb(x, y, z) cout << #x << ": " << x << " " << #y << ": " << y << " " << #z << ": " << z << endl;
#define debbbb(x, y, z, a) cout << #x << ": " << x << " " << #y << ": " << y << " " << #z << ": " << z << " " << #a <<": "<< a <<endl

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// useful function
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

#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

int main()
{
    stack<string>my;
    int t;
    sc(t);
    for(int i=0; i<t; i++)
    {
        char s[100];
        cin>>s;
        if(s[0]=='S')
        {
            string name;
            cin>>name;
            my.push(name);
        }
        else if(s[0]=='K')
        {
            if(!my.empty())
            {
                my.pop();
            }
        }
        else
        {
            if(my.empty())
            {
                cout<<"Not in a dream"<<endl;
            }
            else
            {
                cout<<my.top()<<endl;
            }
        }
    }
    return 0;
}
