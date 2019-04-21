#include "bits/stdc++.h"
using namespace std;

int *ar;

void genrate(int m,int n){
    ar[1]=1;
    ar[2]=2;
    ar[3]=3;
    for(int i=4; i<=n; i++){
        ar[i]=(ar[i-1]+ar[i-2]+ar[i-3])%m+1;
    }
}

int freq[110];


bool cover(int k){
    for(int i=1; i<=k; i++){
        if(freq[i]<=0)return false;
    }
    return true;
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    ar = (int*) malloc(1000004 * 4);
    while(t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        genrate(m,n);
        memset(freq,0,sizeof(freq));
        int lo=1,hi=1,res=n+10;
        freq[ar[hi]]++;
        while(1){
            if(cover(k)){
                res=min(res,hi-lo);
                if(ar[lo]<=k){freq[ar[lo]]--;}
                lo++;
            }
            else{
                hi++;
                if(hi<=n){
                    if(ar[hi]<=k){freq[ar[hi]]++;}
                }
                else break;
            }
        }
        if(res!=n+10)printf("Case %d: %d\n",cs++,res+1);
        else printf("Case %d: sequence nai\n",cs++);
    }
    return 0;
}
