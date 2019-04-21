#include <bits/stdc++.h>
using namespace std;

int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1};

vector<string>v;
bool visited[101][101];
int r,c;
int n;

void dfs(int i, int j)
{
    if(i < 0 || j < 0 || i >=n|| j>= n||v[i][j] == '.')return;
    v[i][j]='.';
    for(int k=0; k<8; k++)
    {
        int R= i+fx[k];
        int C = j+fy[k];
        dfs(R,C);
    }
}


int main()
{
    int t,c=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        memset(visited,0,sizeof(visited));
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                visited[i][j]=1;
                if(v[i][j]=='x')
                {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        printf("Case %d: %d\n",c++,cnt);
        v.clear();
    }
    return 0;
}
