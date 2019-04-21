#include "bits/stdc++.h"
using namespace std;

int main(){
   // freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
    int n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<long long>first,second,third,fourth;
        for(int i=0; i<n; i++){
            long long a,b,c,d;
            scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
            first.push_back(a);
            second.push_back(b);
            third.push_back(c);
            fourth.push_back(d);
        }
        vector<long long>sum1,sum2;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                long long add=(first[i]+second[j]);
                sum1.push_back(add);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                long long add=-(third[i]+fourth[j]);
                sum2.push_back(add);
            }
        }
        sort(sum1.begin(),sum1.end());
        int sz=sum2.size();
        int cnt=0;
        for(int i=0; i<sz; i++){
            cnt+=upper_bound(sum1.begin(),sum1.end(),sum2[i])-lower_bound(sum1.begin(),sum1.end(),sum2[i]);
        }
        printf("%d\n",cnt);
        if(t)printf("\n");
    }
    return 0;
}
