#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,k,res=0;
        scanf("%d%d",&n,&k);
        for(int i=1; i<=n; i++){
            res=(res+k)%i;
        }
        printf("Case %d: %d\n",cs++,res+1);
    }
    return 0;
}
