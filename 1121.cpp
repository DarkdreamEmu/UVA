#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,s;
    while(scanf("%lld%lld",&n,&s)==2){
        long long a[n+10];
        for(long long i=0; i<n; i++){
            scanf("%lld",&a[i]);
        }
        long long sum=0,mn=n+1,lo=0,hi=0;
        sum=a[0];
        while(hi<n){
            if(sum>=s){
                mn=min(hi-lo+1,mn);
            }
            if(sum>=s&&lo<hi){
                sum-=a[lo];
                lo++;
            }
            else if(sum<s){
                hi++;
                if(hi<n)sum+=a[hi];
            }
        }
        if(mn==n+1)mn=0;
        printf("%d\n",mn);
    }
    return 0;
}
