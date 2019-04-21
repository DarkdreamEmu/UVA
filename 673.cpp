#include <bits/stdc++.h>
using namespace std;

int main(){
//freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        if(!s.size()){
            cout<<"Yes"<<endl;
            continue;
        }
        stack<char>stk;
        int sz=s.size();
        for(int i=0; i<sz; i++){
            if(!stk.empty()&&s[i]==')'&&stk.top()=='('){
                stk.pop();
            }
            else if(!stk.empty()&&s[i]==']'&&stk.top()=='['){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
        if(stk.empty()){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
