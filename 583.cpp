#include <bits/stdc++.h>
using namespace std;

vector<int>divisor;

void prime_divisor(int n){
    while(n%2==0){
        divisor.push_back(2);
        n/=2;
    }
    int sq=sqrt(n);
    for(int i=3; i<=sq; i+=2){
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
    int n;
    while(scanf("%d",&n)&&n){
        int pr=n;
        if(n<0){
            divisor.push_back(-1);
            n=(n*-1);
        }
        prime_divisor(n);
        printf("%d = ",pr);
        int sz=divisor.size();
        for(int i=0; i<sz; i++){
            printf("%d",divisor[i]);
            if(i<sz-1){
                printf(" x ");
            }
        }
        printf("\n");
        divisor.clear();
    }
    return 0;
}
