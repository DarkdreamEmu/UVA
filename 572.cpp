#include <bits/stdc++.h>
using namespace std;

int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};

vector<string>v;
bool visited[101][101];
int r,c;

int dfs(int i,int j)
{
    visited[i][j]=1;
    for(int k=0; k<8; k++)
    {
        if(((i+fx[k])>=0&&(i+fx[k])<r)&&((j+fy[k])>=0&&(j+fy[k])<c))
        {
            int R=i+fx[k];
            int C=j+fy[k];
            if(v[R][C]=='@'&&!visited[R][C])
            {
                dfs(R,C);
            }
        }
    }

}

int main()
{
    string s;
    while(cin>>r>>c&&r+c)
    {
        for(int i=0; i<r; i++)
        {
            cin>>s;
            v.push_back(s);
        }
        memset(visited,0,sizeof(visited));
        int cnt=0;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(!visited[i][j])
                {
                    visited[i][j]=1;
                    if(v[i][j]=='@')
                    {
                        cnt++;
                        dfs(i,j);
                    }
                }
            }
        }
        cout<<cnt<<endl;
        v.clear();
    }
    return 0;
}
