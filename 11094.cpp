#include <bits/stdc++.h>
using namespace std;
#define MAX 21

char mat[MAX][MAX],c;
int X[4]={-1,0,0,1};
int Y[4]={0,-1,1,0};
int color[MAX][MAX],n,m,pn,pm,p;

int dfs(int i,int j)
{
    int vx,vy,k;
    if(color[i][j]==0)
    {
        color[i][j]=1;
        p++;
    }
    for(k=0; k<4; k++)
    {
        vx=i+X[k];
        vy=(j+Y[k])%n;

        if(vy<0)
        {
              vy=n-1;
        }

        if(mat[vx][vy]== c &&color[vx][vy]==0)
        {
            dfs(vx,vy);
        }
    }
    return p;
}
int main()
{

    int i,j,k,len,test=0,x;
    while(scanf("%d %d",&m,&n)==2)
    {

        getchar();
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf(" %c",&mat[i][j]);
            }
        }
        scanf("%d %d",&pm,&pn);
        c=mat[pm][pn];
        dfs(pm,pn);

        int k=0,b;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                p=0;
                if(mat[i][j]==c && color[i][j]==0)
                {
                   x=dfs(i,j);
                    if(k<x)
                    {
                        k=x;
                    }
                }
            }
        }

        printf("%d\n",k);
        memset(color,0,sizeof(color));
        memset(mat,'\0',sizeof(mat));
    }
    return 0;
}
