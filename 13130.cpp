#include "bits/stdc++.h"
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int ar[10];
        for(int i=0; i<5; i++){
            scanf("%d",&ar[i]);
        }
        bool ok=true;
        for(int i=0; i<4; i++){
            if(ar[i]+1!=ar[i+1])ok=false;
        }
        if(ok)puts("Y");
        else puts("N");
    }
    return 0;
}
