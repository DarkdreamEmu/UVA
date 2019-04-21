#include <bits/stdc++.h>
using namespace std;

int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};

char s[100][100];
bool visited[100][100];
int n;

int dfs(int i,int j)
{
    visited[i][j]=1;
    for(int k=0; k<8; k++)
    {
        if(((i+fx[k])>=0&&(i+fx[k])<n)&&((j+fy[k])>=0&&(j+fy[k])<n))
        {
            int R=i+fx[k];
            int C=j+fy[k];
            if(s[R][C]=='1'&&!visited[R][C])
            {
                dfs(R,C);
            }
        }
    }

}

int main()
{
    int c=1;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
        }
        memset(visited,0,sizeof(visited));

        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(s[i][j]=='1'&&!visited[i][j])
                {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",c++,cnt);
    }
    return 0;
}
