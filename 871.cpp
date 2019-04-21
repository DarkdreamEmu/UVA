#include <bits/stdc++.h>
using namespace std;

char s[26][26];
bool visited[26][26];
//vector<int>result;
int cnt;
int n=0,l;

int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1};

int dfs(int i,int j)
{
    s[i][j]='0';
    cnt++;
    for(int k=0; k<8; k++)
    {
        if(((i+fx[k])>=0&&(i+fx[k])<n)&&((j+fy[k])>=0&&(j+fy[k])<l))
        {
            int R=i+fx[k];
            int C=j+fy[k];
            if(s[R][C]=='1')
            {
                dfs(R,C);
            }
        }
    }
    return cnt;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d\n\n",&t);
    while(t--)
    {
        n=0;
        while(1)
        {
            gets(s[n]);
            if(!strcmp(s[n++],""))
            {
                break;
            }
        }
        l= strlen(s[0]);

        int mx=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<l; j++)
            {
                if(s[i][j]=='1')
                {
                    cnt=0;
                    int r=dfs(i,j);
                    mx=max(r,mx);
                }
            }
        }

        cout<<mx<<endl;
        if(t)
        {
            printf("\n");
        }

    }
    return 0;
}
