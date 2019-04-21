#include <bits/stdc++.h>
using namespace std;

int R,C;
int mat[110][110];

int mxhistogram(int row[]){
    stack<int>result;
    int top;
    int mxarea=0;
    int area=0;

    int i=0;
    while(i<C){
        if(result.empty()||row[result.top()]<=row[i]){
            result.push(i++);
        }
        else{
            top=row[result.top()];
            result.pop();
            area=top*i;
            if(!result.empty()){
                area=top*(i-result.top()-1);
            }
            mxarea=max(area,mxarea);
        }
    }

    while(!result.empty()){
        top=row[result.top()];
        result.pop();
        area=top*i;
        if(!result.empty()){
            area=top*(i-result.top()-1);
        }
        mxarea=max(area,mxarea);
    }
    return mxarea;
}

int mxsubractangle(){
    int res=mxhistogram(mat[0]);
    for(int i=1; i<R; i++){
        for(int j=0; j<C; j++){
            if(mat[i][j]){
                mat[i][j]+=mat[i-1][j];
            }
        }
        res=max(res,mxhistogram(mat[i]));
    }
    return res;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&R,&C)&&(R+C)){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                int tm;
                scanf("%d",&tm);
                mat[i][j]=(tm==0?1:0);
            }
        }
        printf("%d\n",mxsubractangle());
    }
    return 0;
}

