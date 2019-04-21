#include "bits/stdc++.h"
using namespace std;

int x[] = {+0,+0,+1,-1,-1,+1,-1,+1};;
int y[] = {-1,+1,+0,+0,+1,+1,-1,-1};

char G[100][100];
string match;
int ROW,COL;
int Lr,Lc;

bool valid(int R,int C){
    return (R>=0&&R<ROW&&C>=0&&C<COL);
}

bool Find(int row,int col){
    if( G[row][col] != (match[0]) )return false;
    int sz=match.size(),j;
    for(int i=0; i<8; i++){
        int R=x[i]+row,C=y[i]+col;
        for(j=1; j<sz; j++){
            if( !valid(R,C) )break;
            if( !valid(R,C) )break;
            if( G[R][C] != (match[j]) )break;
            if(j==sz-1){Lr=R;Lc=C;return true;}
            R+=x[i],C+=y[i];
        }
    }
    return false;
}

void pattern_search(){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if( Find(i,j) ){
                printf("%d,%d %d,%d\n",i+1,j+1,Lr+1,Lc+1);
                return ;
            }
        }
    }
    printf("Not found\n");
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
      while(scanf("%d",&ROW)==1){
        COL=ROW;
        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                char ch;
                scanf(" %c",&ch);
                G[i][j]=ch;
            }
        }
        while( cin >>match){
            if(match=="0")break;
            else pattern_search();
        }
    }
    return 0;
}


