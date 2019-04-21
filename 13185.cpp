#include "bits/stdc++.h"
using namespace std;

int F[1100];

void pre(){
    for(int i=2; i<=1010; i++){
        int sum=0;
        F[i]=0;
        for(int j=1; j<i; j++){
            if(i%j==0)sum+=j;
        }
        F[i]=sum;
    }
}

int main(){
    pre();
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(F[n]==n)puts("perfect");
        else if(F[n]<n)puts("deficient");
        else puts("abundant");
    }
    return 0;
}
