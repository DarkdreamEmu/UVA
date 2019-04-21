#include <bits/stdc++.h>
using namespace std;

#define N 5842
typedef long long ll;
ll ugly[N+10];


ll ugly_number(){
    ll i2=0,i3=0,i5=0,i7=0;
    ll nex_mul_2=2;
    ll nex_mul_3=3;
    ll nex_mul_5=5;
    ll nex_mul_7=7;
    ll next_ugly=1;
    ugly[0]=1;

    for(ll i=1; i<N; i++){
        next_ugly=min(nex_mul_2,min(nex_mul_3,min(nex_mul_5,nex_mul_7)));
        ugly[i]=next_ugly;
        if(next_ugly==nex_mul_2){
            i2+=1;
            nex_mul_2=ugly[i2]*2;
        }
        if(next_ugly==nex_mul_3){
            i3+=1;
            nex_mul_3=ugly[i3]*3;
        }
        if(next_ugly==nex_mul_5){
            i5+=1;
            nex_mul_5=ugly[i5]*5;
        }
        if(next_ugly==nex_mul_7){
            i7+=1;
            nex_mul_7=ugly[i7]*7;
        }
    }
}

int main(){
    ll n;
    ugly_number();
    while(scanf("%lld",&n)&&n){
        printf("The %d",n);
        if(n%10==1 && (n/10)%10!=1) printf("st");
        else if(n%10==2 && (n/10)%10!=1) printf("nd");
        else if(n%10==3 && (n/10)%10!=1) printf("rd");
        else printf("th");
         printf(" humble number is %lld.\n",ugly[n-1]);
    }
    return 0;
}
