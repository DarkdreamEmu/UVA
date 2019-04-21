#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int A[n+10],B[n+10];
        for(int i=0; i<n; i++){
            scanf("%d",&A[i]);
        }
        for(int i=0; i<n; i++){
            scanf("%d",&B[i]);
        }
        int LI=0,LD=0;
        int LIS[n+10],LDS[n+10];
        for(int i=0; i<n; i++){
            LIS[i]=LDS[i]=B[i];
            for(int j=0; j<i; j++){
                if(A[j]<A[i]){
                    LIS[i]=max(LIS[i],B[i]+LIS[j]);
                }
                if(A[j]>A[i]){
                    LDS[i]=max(LDS[i],B[i]+LDS[j]);
                }
            }
            LI=max(LI,LIS[i]);
            LD=max(LD,LDS[i]);
        }
        if(LI>=LD)printf("Case %d. Increasing (%d). Decreasing (%d).\n",cs++,LI,LD);
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n",cs++,LD,LI);
    }
    return 0;
}
