#include "bits/stdc++.h"
using namespace std;

long long sum[60101];

int tot(int num){
    int cnt=0;
    while(num!=0){
        cnt++;
        num/=10;
    }
    return cnt;
}

string make(int num){
    string m="";
    while(num!=0){
        char ch=(num%10)+'0';
        m+=ch;
        num/=10;
    }
    reverse(m.begin(),m.end());
    return m;
}

int main(){
    string tmp="";
    long long dig=0;
    for(int i=1; i<=60001; i++){
        dig+=(tot(i));
        sum[i]=(sum[i-1]+dig);
        tmp+=make(i);
    }
    int t;
    scanf("%d",&t);
    while(t--){
        long long n;
        scanf("%lld",&n);
        int low=1,high=60001,mid,ans=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            if(sum[mid]>=n){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        cout<<tmp[n-sum[ans-1]-1]<<endl;
    }
    return 0;
}
