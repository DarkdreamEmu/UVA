#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int pos=1;
        for(int i=0; i<n; i++){
            int num;
            scanf("%d",&num);
            if(num==pos){
                pos++;
            }
        }
        printf("Case %d: %d\n",cs++,n-pos+1);
    }
    return 0;
}
