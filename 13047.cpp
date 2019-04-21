#include "bits/stdc++.h"
using namespace std;

int main(){
//freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        int res=0;
        int sz=s.size();
        for(int i=0; i<sz; i++){
            int cnt=0,A=0;
            if(s[i]=='-'){
                i++;
                A=1;
                cnt++;
                while(s[i]=='-'){
                    cnt++;
                    i++;
                    A=1;
                }
                if(s[i]=='>'){
                    cnt++;
                    res=max(cnt,res);
                    A=0;
                }
            }
            else if(s[i]=='='){
                i++;
                A=1;
                cnt++;
                while(s[i]=='='){
                    i++;
                    cnt++;
                    A=1;
                }
                if(s[i]=='>'){
                    cnt++;
                    A=0;
                    res=max(cnt,res);
                }
            }
            else if(s[i]=='>'){
                cnt++;
                res=max(cnt,res);
            }
            if(A)i--;
        }
        for(int i=sz-1; i>=0; i--){
            int cnt=0,A=0;
            if(s[i]=='-'){
                i--;
                cnt++;
                A=1;
                while(s[i]=='-'){
                    cnt++;
                    i--;
                    A=1;
                }
                if(s[i]=='<'){
                    cnt++;
                    res=max(cnt,res);
                    A=0;
                }
            }
            else if(s[i]=='='){
                i--;
                cnt++;
                A=1;
                while(s[i]=='='){
                    i--;
                    cnt++;
                    A=1;
                }
                if(s[i]=='<'){
                    cnt++;
                    A=0;
                    res=max(cnt,res);
                }
            }
            else if(s[i]=='<'){
                cnt++;
                res=max(cnt,res);
            }
            if(A)i++;
        }
        if(res)printf("Case %d: %d\n",cs++,res);
        else printf("Case %d: -1\n",cs++);
    }
    return 0;
}
