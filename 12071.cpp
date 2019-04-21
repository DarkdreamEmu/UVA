#include <bits/stdc++.h>
using namespace std;

int main(){
    int cs=1,N;
    while(scanf("%d",&N)&&N){
        long long A[N+10];
        for(int i=0; i<N; i++){
            scanf("%lld",&A[i]);
        }
        long long res=0,j=0;
        sort(A,A+N);
        for(int i=1; i<N; i++){
            while(A[j]<A[i]){
                j++;
            }
            res+=j;
        }
        printf("Case %d: %lld\n",cs++,res);
    }
    return 0;
}
