#include "bits/stdc++.h"
using namespace std;

int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

char G[100][100];
string match;
int ROW,COL;

bool valid(int R,int C){
    return (R>=0&&R<ROW&&C>=0&&C<COL);
}

bool Find(int row,int col){
    if( G[row][col] != tolower(match[0]) )return false;
    int sz=match.size(),j;

    for(int i=0; i<8; i++){
        int R=x[i]+row,C=y[i]+col;
        for(j=1; j<sz; j++){
            if( R>=ROW || R<0 || C>=COL || C<0)break;
            if( !valid(R,C) )break;
            if( G[R][C] != tolower(match[j]) )break;
            R+=x[i],C+=y[i];
        }
        if(j>=sz)return true;
    }
    return false;
}

void pattern_search(){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if( Find(i,j) ){
                printf("%d %d\n",i+1,j+1);
                return ;
            }
        }
    }
}

int main(){
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d\n",&t);
    while(t--){
        scanf("%d %d",&ROW,&COL);
        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                char ch;
                scanf(" %c",&ch);
                G[i][j]=tolower(ch);
            }
        }
        int Q;
        scanf("%d",&Q);
        while(Q--){
            cin >> match;
            pattern_search();
        }
        if(t)printf("\n");
    }
    return 0;
}

