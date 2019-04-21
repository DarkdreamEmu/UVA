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
    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--){
        char s[110];
        int i=0,sz;
        while(cin.getline(s,110)&&strlen(s)){
            sz=strlen(s);
            for(int j=0; j<sz; j++){
                mat[i][j]=(s[j]=='1'?1:0);
            }
            i++;
        }
        R=sz;
        C=sz;
        printf("%d\n",mxsubractangle());
        if(t){
            printf("\n");
        }
    }
    return 0;
}
