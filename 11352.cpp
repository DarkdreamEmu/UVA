#include<stdio.h>
#include<string.h>
#include<queue>
#define MAX 101
using namespace std;
int n,m,color[MAX][MAX],cost[MAX][MAX];
int x[8]={-2,-2,-1,-1,1,1,2,2};
int y[8]={-1,1,-2,2,-2,2,-1,1};

int X[8]={-1,-1,-1,0,0,1,1,1};
int Y[8]={-1,0,1,-1,1,-1,0,1};
char mat[MAX][MAX];
void bfs(int i,int j)
{
    int vx,vy,ux,uy,k;
    queue<int>Q;
    color[i][j]=1;
    Q.push(i);
    Q.push(j);
    while(!Q.empty())
    {
         ux=Q.front();
         Q.pop();
         uy=Q.front();
         Q.pop();
         for(k=0;k<8;k++)
         {
             vx=ux+x[k];
             vy=uy+y[k];
             if(vx>=1 && vx<=n && vy>=1 && vy<=m && mat[vx][vy]=='.')
             {
                 if(color[vx][vy]==0)
                 {
                    color[vx][vy]=1;
                 }

             }
         }
    }
}
int bfs1(int i,int j)
{
    int vx,vy,ux,uy,k,cont=0;
    queue<int>Q;
    color[i][j]=1;
    Q.push(i);
    Q.push(j);
    cost[i][j]=0;

    while(!Q.empty())
    {
         ux=Q.front();
         Q.pop();
         uy=Q.front();
         Q.pop();
         for(k=0;k<8;k++)
         {
             vx=ux+X[k];
             vy=uy+Y[k];
             if(vx>=1 && vx<=n && vy>=1 && vy<=m && mat[vx][vy]=='.')
             {
                 if(color[vx][vy]==0)
                 {
                    color[vx][vy]=1;
                    cost[vx][vy]=cost[ux][uy]+1;
                    Q.push(vx);
                    Q.push(vy);
                 }

             }
             if(mat[vx][vy]=='B')
             {
                 cost[vx][vy]=cost[ux][uy]+1;
                return cost[vx][vy];
             }
         }

    }
    return 0;
}

int main()
{
    int test,i,j,k,len,kingi,kingj;
    scanf("%d",&test);
    getchar();
    while(test--)
    {
        scanf("%d %d",&n,&m);
        getchar();
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf(" %c",&mat[i][j]);
                if(mat[i][j]=='A')
                {
                    kingi=i;
                    kingj=j;
                }
            }
        }

        memset(color,0,sizeof(color));

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(mat[i][j]=='Z' && color[i][j]==0)
                {
                    bfs(i,j);
                }
            }

        }

        int sp;
        sp=bfs1(kingi,kingj);
        if(sp==0)
        {
            printf("King Peter, you can't go now!\n");
        }
        else
        {
            printf("Minimal possible length of a trip is %d\n",sp);
        }
        memset(mat,'\0',sizeof(mat));
        kingi=0;
        kingj=0;
    }
    return 0;

}
