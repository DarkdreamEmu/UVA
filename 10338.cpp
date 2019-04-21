#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL fact(int num){
    LL mul=1;
    for(LL i=1; i<=num; i++){
        mul*=i;
    }
    return mul;
}

LL res(LL num,int freq[]){
    LL mul=1;
    for(int i=0; i<26; i++){
        if(freq[i]>=2){
            mul*=(fact(freq[i]));
        }
    }
    return (num/mul);
}

int main(){
    int t;
    int cs=1;
    scanf("%d",&t);
    while(t--){
        int freq[26];
        memset(freq,0,sizeof(freq));
        string s;
        cin>>s;
        int sz=s.size();
        for(int i=0; i<sz; i++){
            freq[s[i]-'A']++;
        }
        LL tak=fact(sz);
        printf("Data set %d: %lld\n",cs++,res(tak,freq));
    }
    return 0;
}
