#include <bits/stdc++.h>
using namespace std;

#define MX 10010
int mark[MX];
int res[MX];

void solve(){
    int i,j;
    memset(mark,1,sizeof(mark));
    memset(res,1,sizeof(res));
    mark[0]=0;
    mark[1]=0;
    for(i=2; i<=MX; i++){
        if(mark[i]){
            for(j=i+i; j<=MX; j+=i){
                mark[j]=0;
            }
        }
    }
    res[0]=res[1]=0;
    for(i=2; i<=MX; i++){
        int cnt=0;
        for(j=1; j<=i; j++){
            if(i%j==0){
                cnt++;
            }
        }
        if(!mark[cnt]){
            res[i]=0;
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        int cnt=0;
        for(int i=a; i<=b; i++){
            if(res[i]){
                if(cnt==0){
                    printf("%d",i);
                }
                else{
                    printf(" %d",i);
                }
                cnt++;
            }
        }
        if(cnt==0){
            printf("-1\n");
        }
        else{
            printf("\n");
        }
    }
    return 0;
}
