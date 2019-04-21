#include <bits/stdc++.h>
using namespace std;

vector<long long>divisor;

void prime_divisor(long long n){
    while(n%2==0){
        divisor.push_back(2);
        n/=2;
    }
    long long sq=sqrt(n);
    for(long long i=3; i<=sq; i+=2){
        while(n%i==0){
            divisor.push_back(i);
            n/=i;
        }
    }
    if(n>2){
        divisor.push_back(n);
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long n;
    while(scanf("%lld",&n)&&n>=0){
        if(n<0){
            n=n*-1;
        }
        prime_divisor(n);
        sort(divisor.begin(),divisor.end());
        int sz=divisor.size();
        for(long long int i=0; i<sz; i++){
            printf("    %lld\n",divisor[i]);
        }
        printf("\n");
        divisor.clear();
    }
    return 0;
}


