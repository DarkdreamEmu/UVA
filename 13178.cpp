#include "bits/stdc++.h"
using namespace std;

int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        long long a;
        scanf("%lld",&a);
        long long res=a*(a+1)/2;
        if(res%3)puts("NO");
        else puts("YES");
    }
    return 0;
}
