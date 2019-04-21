#include <bits/stdc++.h>
using namespace std;

int store[77];

int main(){
    store[1]=store[2]=1;
    for(int i=3; i<=76; i++){
        store[i]=store[i-2]+store[i-3];
    }
    int n;
    while(scanf("%d",&n)==1){
        printf("%d\n",store[n]+store[n-1]);
    }
    return 0;
}
