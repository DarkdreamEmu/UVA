#include <bits/stdc++.h>
using namespace std;

vector<long long>divisor;
map<long long,long long>my;

void prime_divisor(long long n){
    while(n%2==0){
        divisor.push_back(2);
        my[2]++;
        n/=2;
    }
    long long sq=sqrt(n);
    for(long long i=3; i<=sq; i+=2){
        while(n%i==0){
            divisor.push_back(i);
            my[i]++;
            n/=i;
        }
    }
    if(n>2){
        divisor.push_back(n);
        my[n]++;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long n;
    while(scanf("%lld",&n)&&n){
        if(n<0){
            n=n*-1;
        }
        prime_divisor(n);
        if(my.size()>1){
            sort(divisor.begin(),divisor.end());
            printf("%lld\n",divisor[divisor.size()-1]);
        }
        else{
            printf("-1\n");
        }
        divisor.clear();
        my.clear();
    }
    return 0;
}

