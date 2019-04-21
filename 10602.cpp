#include "bits/stdc++.h"
using namespace std;

int check(string a,string b){
    int cnt=0,i=0;
    while(a[i]==b[i]){
        i++;
        cnt++;
    }
    return cnt;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<string>vec;
        map<string,int>freq;
        for(int i=0; i<n; i++){
            string s;
            cin>>s;
            vec.push_back(s);
            freq[s]++;
        }
        map<string,int>visited;
        int res=vec[0].size();
        queue<string>q;
        q.push(vec[0]);
        vector<string>rs;
        while(!q.empty()){
            string take=q.front(),another="";
            rs.push_back(take);
            visited[take]=1;
            q.pop();
            int mx=-1,cnt=0;
            for(int i=0; i<n; i++){
                if(!visited[vec[i]]){
                    int match=check(take,vec[i]);
                    if(match>mx){
                        another=vec[i];
                        mx=match;
                        cnt=another.size()-match;
                    }
                }
            }
            if(another!=""){
                q.push(another);
                res+=cnt;
            }
        }
        printf("%d\n",res);
        int sz=rs.size();
        for(int i=0; i<sz; i++){
            if(freq[rs[i]]==1){
                cout<<rs[i]<<"\n";
            }
            else{
                for(int j=0; j<freq[rs[i]]; j++){
                    cout<<rs[i]<<"\n";
                }
            }
        }
    }
    return 0;
}
