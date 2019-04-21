#include <bits/stdc++.h>
using namespace std;

#define MX 10000001

int mark[MX];
vector<int>prime;

void sieve(){
    int i,j;
    memset(mark,1,sizeof(mark));
    for(i=2; i<MX; i++){
        if(mark[i]){
            prime.push_back(i);
            for(j=i+i; j<MX; j+=i){
                mark[j]=0;
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    sieve();
    int n;
    while(scanf("%d",&n)&&n){
        if(mark[n]){
            printf("0\n");
        }
        else{
           /* for(int i=0; i<20; i++){
                cout<<prime[i]<<" ";
            }
            cout<<endl;*/
            //vector<int>::iterator lo=lower_bound(prime.begin(),prime.end(),n);
            vector<int>::iterator hi=upper_bound(prime.begin(),prime.end(),n);
           // cout<<lo-prime.begin()<<" "<<hi-prime.begin()<<endl;
            int res=prime[hi-prime.begin()]-prime[hi-prime.begin()-1];
            printf("%d\n",res);
        }
    }
    return 0;
}
