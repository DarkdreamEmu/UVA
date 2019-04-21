#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int main(){
    LL a,b;
    int cs=1;
    while(scanf("%lld %lld",&a,&b)&&(a+b)){
        LL res=(a*(a-1)/2)*(b*(b-1)/2);
        printf("Case %d: %lld\n",cs++,res);
    }
    return 0;
}
