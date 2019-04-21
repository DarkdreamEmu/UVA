#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        map<string,int>res;
        vector<string>take;
        string s;
        while(getline(cin,s)&&s.size()){
            take.push_back(s);
        }
        int sz=take.size();
        for(int i=0; i<sz; i++){
            for(int j=i+1; j<sz; j++){
                string a=take[i]+take[j];
                string b=take[j]+take[i];
                res[a]++;
                res[b]++;
            }
        }
        map<string,int>::iterator it=res.begin();
        string p;
        int mx=0;
        while(it!=res.end()){
            if(it->second>mx){
                mx=it->second;
                p=it->first;
            }
            it++;
        }
        cout<<p<<endl;
        if(t){
            printf("\n");
        }
    }
    return 0;
}
