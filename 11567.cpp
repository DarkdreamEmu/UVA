#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    while(scanf("%lld",&n)!=EOF){
        long long s=0L;
        long long cnt=0L;
        while(n!=0L){
            if(n%2L==0L){
                n=n/2L;
            }
            else{
                if(((n-1)/2L)%2L==0||((n-1)==2)){
                    n--;
                }
                else{
                    n++;
                }
            }
            cnt++;
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
