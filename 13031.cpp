#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        vector< pair<int,int> >v;
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            int a,b;
            scanf("%d %d",&a,&b);
            v.push_back(make_pair(b,a));
        }
        sort(v.begin(),v.end());
        long long sum=0;
        long long res=0;
        for(int i=n-1; i>=0; i--){
            sum+=v[i].second;
            res=max(res,sum*v[i].first);
        }
        printf("Case %d: %lld\n",cs++,res);
        v.clear();
    }
    return 0;
}
