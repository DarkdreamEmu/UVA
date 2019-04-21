#include <bits/stdc++.h>
using namespace std;

int x[6] = {0,0,0,0,1,-1};
int y[6] = {-1,0,1,0,0,0};
int z[6] = {0,1,0,-1,0,0};
#define mx 35
char s[mx][mx][mx];
bool visited[mx][mx][mx];
int cost[mx][mx][mx];
int sx,sy,sz,ex,ey,ez;
int l,r,c;

bool valid(int aa,int bb,int cc){
    return ((aa>=0&&aa<l)&&(bb>=0&&bb<r)&&(cc>=0&&cc<c));
}

void bfs(int aa,int bb,int cc){
    queue<int>q;
    memset(visited,0,sizeof(visited));
    memset(cost,0,sizeof(cost));
    q.push(aa);
    q.push(bb);
    q.push(cc);

    cost[aa][bb][cc]=0;
    visited[aa][bb][cc]=1;

    while(!q.empty()){
        int ux=q.front();
        q.pop();

        int uy=q.front();
        q.pop();

        int uz=q.front();
        q.pop();
        for(int i=0; i<6; i++){
            int vx=ux+x[i];
            int vy=uy+y[i];
            int vz=uz+z[i];
            if(valid(vx,vy,vz)&&(s[vx][vy][vz]!='#')&&!visited[vx][vy][vz]){
                cost[vx][vy][vz]=cost[ux][uy][uz]+1;
                visited[vx][vy][vz]=1;
                q.push(vx);
                q.push(vy);
                q.push(vz);
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d%d",&l,&r,&c)&&(l+r+c)){
        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                for(int k=0; k<c; k++){
                    scanf(" %c",&s[i][j][k]);
                    if(s[i][j][k]=='S'){
                        sx=i;
                        sy=j;
                        sz=k;
                    }
                    if(s[i][j][k]=='E'){
                        ex=i;
                        ey=j;
                        ez=k;
                    }
                }
            }
            getchar();
        }
        bfs(sx,sy,sz);
        if(cost[ex][ey][ez]==0){
            printf("Trapped!\n");
        }
        else{
            printf("Escaped in %d minute(s).\n",cost[ex][ey][ez]);
        }
    }
    return 0;
}
