#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)==1){
        int res=0;
        vector<int>v;
        for(int i=0; i<n; i++){
            v.push_back(1);
            long long sum=0;
            for(int j=0; j<v.size(); j++){
                sum=(sum*10+v[j])%n;
            }
            if(sum==0){
                break;
            }
        }
        printf("%d\n",v.size());
    }
    return 0;
}
