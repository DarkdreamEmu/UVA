#include "bits/stdc++.h"
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    while(n--){
        string s;
        cin>>s;
        int sz=s.size();
        bool ok=true;
        int M=s.find('M');
        int E=s.find('E');
        if(M==-1||E==-1||M==0||E==0||(E==s.size()-1))ok=false;
        if(E-M==1)ok=false;
        if(E<M||M>E)ok=false;
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=0; i<M&&ok; i++){
            if(s[i]=='?')cnt1++;
            else  ok=false;
        }
        for(int i=M+1; i<E&&ok; i++){
            if(s[i]=='?')cnt2++;
            else  ok=false;
        }
        for(int i=E+1; i<sz; i++){
            if(s[i]=='?')cnt3++;
            else  ok=false;
        }
        if(ok&&cnt1+cnt2==cnt3)puts("theorem");
        else puts("no-theorem");
    }
    return 0;
}
