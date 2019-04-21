#include <bits/stdc++.h>
using namespace std;

int josephus(int n,int k){
    if(n==1){
        return 1;
    }
    else{
        return (josephus(n-1,k)+k-1)%n+1;
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)&&n){
        for(int i=1; i<=1050; i++){
            int check=josephus(n-1,i);
            if(check==1){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}


