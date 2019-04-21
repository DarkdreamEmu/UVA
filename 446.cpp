#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
map<char,ll> m;
void fillMap(){
    ll count=0;
    for(char i='0';i<='9';i++){
        m[i] = count++;
    }
    for(char i='A';i<='F';i++){
        m[i] = count++;
    }
}
ll toInt(string s){
    ll digit=0,ans=0;
    for(ll i=s.length()-1;i>=0;i--){
        ans+=pow(16,digit++)*m[s[i]];
    }
    return ans;
}
string toBinary(ll n){
    string s;
    if(n==0) s.push_back('0');
    while(n){
        if(n%2==0) s.push_back('0');
        else s.push_back('1');
        n/=2;
    }
    return s;
}
int main(){
    ll t;
    cin>>t;
    fillMap();
    while(t--){
        string a,b;
        char c;
        cin>>a>>c>>b;
        ll A = toInt(a);
        ll B = toInt(b);

        ll ans;
        switch(c){
            case '+': {ans=A+B;break;}
            case '-': {ans=A-B;break;}
        }

        a = toBinary(A);
        b = toBinary(B);

        ll lenA = 13 - a.size() ,  lenB = 13 - b.size();
        for(ll i=0;i<lenA;i++) cout<<0;
        for(ll i=a.size()-1;i>=0;i--) cout<<a[i];
        cout<<" "<<c<<" ";
        for(ll i=0;i<lenB;i++) cout<<0;
        for(ll i=b.size()-1;i>=0;i--) cout<<b[i];
        cout<<" = "<<ans<<endl;
    }
    return 0;
}
