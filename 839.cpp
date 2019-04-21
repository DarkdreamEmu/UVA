#include <bits/stdc++.h>
using namespace std;

bool ok;

long long check(){
    long long int a,b,c,d;
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    if(a==0){
        a=check();
    }
    if(c==0){
        c=check();
    }
    if(a*b!=c*d){
        ok=false;
    }
    return a+c;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ok=true;
        check();
        if(ok){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        if(t){
            printf("\n");
        }
    }
    return 0;
}

