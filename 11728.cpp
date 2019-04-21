#include <bits/stdc++.h>
using namespace std;



#define N 1000
long long take[1001];

void calculate(){
    for(long long n=1; n<=N; n++){
        long long sum=0;
        for(long long i=1; i<=n; i++){
            if(n%i==0){
                sum+=i;
            }
        }
        take[n]=sum;
    }
}

int main(){
    calculate();
    int n;
    int cs=1;
    while(scanf("%d",&n)&&n){
        int res;
        bool ok=false;
        for(int i=1000; i>=0; i--){
            if(take[i]==n){
                res=i;
                ok=true;
                break;
            }
        }
        if(ok){
            printf("Case %d: %d\n",cs++,res);
        }
        else{
            printf("Case %d: %d\n",cs++,-1);
        }
    }
    return 0;
}
