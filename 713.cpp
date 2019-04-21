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

string rev(string s)
{
    string res="";
    int siz=s.size();
    RFOR(i,siz,0)
    {
        res+=s[i];
    }
    return res;
}

string add(string a, string b)
{
    int al=a.size()-1;
    int bl=b.size()-1;

    int carry=0;
    string result="";

    while(al>=0 && bl>=0)
    {
        int temp = (int)(a[al] - '0') + (int)(b[bl] - '0') + carry ;
        carry = 0;
        if(temp > 9 )
        {
            carry=1;
            temp=temp-10;
        }

        result+=char(temp + '0');
        al--;
        bl--;
    }

    while(al>=0)
    {
        int temp = (int)(a[al] - '0') + carry ;
        carry = 0;
        if(temp>9)
        {
            carry=1;
            temp=temp%10;
        }

        result+=char(temp + '0');
        al--;
    }

    while(bl>=0)
    {
        int temp = (int)(b[bl] - '0') + carry ;
        carry = 0;
        if(temp>9)
        {
            carry=1;
            temp=temp%10;
        }

        result+=char(temp + '0');
        bl--;
    }

    if(carry)
        result+="1";

    string addition="";

    for(int i=result.size()-1; i>=0; i--)
        addition+=result[i];   // reversing the answer

    return addition;
}

string trim(string a)   // for removing leading 0s
{
    string res="";
    int i=0;

    while(a[i]=='0')
        i++;

    for(; i<a.size(); i++)
        res+=a[i];

    return res;
}


int main()
{
    //read("in.txt");
    //write("out.txt");
    int t;
    si(t);
    while(t--)
    {
        string s1,s2,rev1,rev2;
        cin>>s1>>s2;
        rev1=rev(s1);
        rev2=rev(s2);
        string tempo=add(rev1,rev2);
        string ress=rev(tempo);
        int cnt=0;
        if(ress[cnt]=='0')
        {
            string prin="";
            while(ress[cnt]=='0')
            {
                cnt++;
            }
            FOR(i,cnt,ress.size())
            {
                prin+=ress[i];
            }
            cout<<prin<<endl;
        }
        else
        {
            cout<<ress<<endl;
        }
    }
    return 0;
}



