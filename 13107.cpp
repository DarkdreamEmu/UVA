#include "bits/stdc++.h"
using namespace std;

int check(int ch){
    if(ch==2)return 5;
    if(ch==5)return 2;
    if(ch==6)return 9;
    if(ch==9)return 6;
    if(ch==12)return 15;
    if(ch==15)return 12;
    if(ch==16)return 19;
    if(ch==19)return 16;
    if(ch==20)return 50;
    if(ch==21)return 51;
    if(ch==22)return 55;
    if(ch==23)return 53;
    if(ch==24)return 54;
    if(ch==25)return 52;
    if(ch==26)return 59;
    return ch;
}

int main(){
    string s;
    while(cin>>s){
        map<char,int>my;
        int sz=s.size();
        vector<int>res;
        int cnt=1;
        for(int i=0; i<sz; i++){
            if(!my[s[i]]){
                my[s[i]]=cnt;
                res.push_back(cnt);
                cnt++;
            }
            else{
                res.push_back(my[s[i]]);
            }
        }
        int vs=res.size();
        for(int i=0; i<vs; i++){
            printf("%d",check(res[i]));
        }
        printf("\n");
        res.clear();
        my.clear();
    }
    return 0;
}
