#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        int sz=s.size();
        int res=0;
        for(int i=0; i<sz; i++){
            int fq[26]={0};
            int tm=0;
            for(int j=i; j<sz; j++){
                fq[s[j]-'a']++;
                if(fq[s[j]-'a']&1)tm++;
                else tm--;
                int ra=j-i+1;
                if((ra&1)&&tm==1)res++;
                if(!(ra&1)&&tm==0)res++;
            }
        }
        printf("Case %d: %d\n",cs++,res);
    }
    return 0;
}
