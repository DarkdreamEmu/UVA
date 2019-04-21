#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        int sz=s.size();
        int i=0,j=sz-1;
        string tak="",res;
        int st=0,en=0,mx=0;
        for(int i=0; j>=0;){
            if(s[i]==s[j]){
                tak="";
                while(s[i]==s[j]&&i<sz){
                    tak+=s[j];
                    i++;
                    j--;
                }
                if(tak.size()>mx){
                    mx=tak.size();
                    res=tak;
                }
                i=0;
            }
            else{
                i=0;
                j--;
            }
        }
        reverse(res.begin(),res.end());
        cout<<res<<endl;
    }
    return 0;
}
