#include "bits/stdc++.h"
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        int sz=s.size();
        set<char>my;
        my.clear();
        for(int i=0; i<sz; i++){
            my.insert(s[i]);
        }
        if(my.size()==s.size()){
            set<char>::iterator it=my.begin();
            string res="";
            while(it!=my.end()){
                res+=*it;
                it++;
            }
            cout<<res;
            printf("\n");
        }
        else{
            set<char>::iterator it=my.begin();
            char ch=*it;
            string res="";
            res+=*it;
            int pos=s.size()-my.size();
            for(int i=0; i<pos; i++){
                res+=*it;
            }
            it++;
            while(it!=my.end()){
                res+=*it;
                it++;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
