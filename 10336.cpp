#include <bits/stdc++.h>
using namespace std;

char v[100][100];
bool visited[100][100];


int dfs(int i,int j,char a)
{
    visited[i][j]=1;
    if(v[i][j+1]==a&&!visited[i][j+1])
    {
        dfs(i,j+1,a);
    }
    if(v[i+1][j]==a&&!visited[i+1][j])
    {
        dfs(i+1,j,a);
    }
    if(v[i-1][j]==a&&!visited[i-1][j])
    {
        dfs(i-1,j,a);
    }
    if(v[i][j-1]==a&&!visited[i][j-1])
    {
        dfs(i,j-1,a);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int r,c;
    int test=1;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        int freq[128];
        string s;
        for(int i=0; i<r; i++)
        {
            cin>>v[i];
        }

        memset(visited,0,sizeof(visited));
        memset(freq,0,sizeof(freq));

        char a;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(!visited[i][j])
                {
                    a=v[i][j];
                    freq[a]++;
                    dfs(i,j,a);
                }
            }
        }
        int res=0;
        for(int i=97; i<128; i++)
        {
            res=max(res,freq[i]);
        }

        printf("World #%d\n",test++);
        for(int j=res; j>0; j--)
        {
            for(int k=97; k<=122; k++)
            {
                if(freq[k]==j)
                {
                    printf("%c: %d\n",k,j);
                }
            }
        }

    }
    return 0;
}
