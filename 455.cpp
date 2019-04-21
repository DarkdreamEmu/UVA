#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        int sz=s.size();
        for(int i=1; i<=sz; i++){

            string tmp=s.substr(0,i);
            int tmpsz=tmp.size();
            string str="";

            for(int j=1; j<=sz/tmpsz; j++){
                str+=tmp;
            }
            if(str==s){
                printf("%d\n",tmpsz);
                break;
            }
        }
        if(t){
            printf("\n");
        }
    }
    return 0;
}
