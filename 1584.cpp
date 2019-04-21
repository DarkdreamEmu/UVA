#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        string mn="Z";
        int sz=s.size();
        s+=s;
        for(int i=0; i<sz; i++){
            mn=min(mn,s.substr(i,sz));
        }
        cout<<mn<<endl;
    }
    return 0;
}
