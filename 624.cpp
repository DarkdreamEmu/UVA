 #include <bits/stdc++.h>
 using namespace std;

 int track[110],m,N,best,sum;
 vector<int>bestpath;

 void backtrack(vector<int>path,int sum,int n){
     sum+=track[n];
     path.push_back(track[n]);
     if(sum>best||(sum==best&&path.size()>bestpath.size())){
        best=sum;
        bestpath=path;
     }
     for(int i=n+1; i<m; i++){
        if(sum+track[i]<=N){
            backtrack(path,sum,i);
        }
     }
 }

 int main(){
     while(scanf("%d",&N)==1){
        scanf("%d",&m);
        for(int i=0; i<m; i++){
            scanf("%d",&track[i]);
        }
        best=0;
        for(int i=0; i<m; i++){
            vector<int>path;
            backtrack(path,0,i);
        }
        int sz=bestpath.size();
        for(int i=0; i<sz; i++){
            printf("%d",bestpath[i]);
            if(i<sz-1){
                printf(" ");
            }
        }
        printf(" sum:%d\n",best);
     }
     return 0;
 }
