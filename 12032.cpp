#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        long long int ar[n+10];
        ar[0]=0;
        for(int i=1; i<=n; i++){
            scanf("%lld",&ar[i]);
        }
        long long mx=-1000000000;
        for(int i=1; i<=n; i++){
            if(ar[i]-ar[i-1]>mx){
                mx=ar[i]-ar[i-1];
            }
        }
        int res=mx;
        for(int i=1; i<=n; i++){
            if(ar[i]-ar[i-1]>mx){
                res++;
                break;
            }
            if(ar[i]-ar[i-1]==mx){
                mx--;
            }
        }
        printf("Case %d: %d\n",cs++,res);
    }
    return 0;
}
