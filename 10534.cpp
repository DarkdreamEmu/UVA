#include "bits/stdc++.h"
using namespace std;

void LIS(int X[],int another[],int n){
    int lenght=0;
    int dp[n+10];
    for(int i=0; i<n; i++){
        int low=1,high=lenght;
        while(low<=high){
            int mid=ceil((low+high)/2);
            if(X[dp[mid]]<X[i]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        int pos=low;
        dp[pos]=i;
        another[i]=pos;
        if(pos>lenght){
            lenght=pos;
        }
    }
}

int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1){
        int X[n+10];
        int Y[n+10];
        for(int i=0; i<n; i++){
            int num;
            scanf("%d",&num);
            X[i]=num;
            Y[n-i-1]=num;
        }
        int T1[n+10],T2[n+10];
        LIS(X,T1,n);
        LIS(Y,T2,n);
        int res=0;
        for(int i=0; i<n; i++){
            res=max(res,min(T1[i],T2[n-i-1]));
        }
        printf("%d\n",(2*res-1));
    }
    return 0;
}
