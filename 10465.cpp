#include <bits/stdc++.h>
using namespace std;

int tme[11100];
int num[11100];

void knapsack(int m,int t){
    for(int i=0; i+m<=t; i++){
        if(tme[i+m]<tme[i]+m){
            tme[i+m]=tme[i]+m;
            num[i+m]=num[i]+1;
        }
    }
}

int main(){
    int n,m,t;
    while(scanf("%d%d%d",&m,&n,&t)!=EOF){
        if(m>n){
            swap(m,n);
        }
        fill(tme,tme+t+1,0);
        fill(num,num+t+1,0);
        knapsack(m,t);
        knapsack(n,t);

        if(tme[t]==t){
            printf("%d\n",num[t]);
        }
        else{
            printf("%d %d\n",num[tme[t]], t-tme[t]);
        }
    }
    return 0;
}
