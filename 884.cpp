#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001
int res[MAXN];
bool mark[MAXN];
vector<int>prime;


void sieve(){
    memset(mark,true,sizeof(mark));
    mark[0]=mark[1]=false;
    int sq=(int)sqrt(MAXN);
    for(int i=2; i<=MAXN; i++){
        if(mark[i]){
            prime.push_back(i);
            for(int j=i+i; j<=MAXN; j+=i){
                mark[j]=false;
            }
        }
    }
}

void calcu(){
    sieve();
    res[1]=0;
    for(int i=2; i<MAXN; i++){
        res[i]=res[i-1];
        int n=i,j=0;
        while(!mark[n]){
            if(n%prime[j]==0){
                res[i]++;
                n/=prime[j];
            }
            else{
                j++;
            }
        }
        if(mark[n]){
            res[i]++;
        }
    }
}


int main(){
    int n;
    calcu();
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",res[n]);
    }
    return 0;
}
