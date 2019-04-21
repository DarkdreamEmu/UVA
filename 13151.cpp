#include "bits/stdc++.h"
using namespace std;

int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    char s[100];
    int m;
    while(scanf("%s %d",&s,&m)&&(strcmp(s,"0")!=0&&m!=0)){
        int n;
        if(s[0]=='0'&&s[1]=='x'){
            sscanf(s,"%X",&n);
        }
        else if(s[0]=='0'){
            sscanf(s,"%o",&n);
        }
        else{
            sscanf(s,"%d",&n);
        }
        int res=0;
        while(m--){
            string s;
            int num;
            cin>>s>>num;
            if(s=="i"){
                num==n ? res++ : res;
                n=num;
            }
            else if(s=="i++"){
                num==n? res++ :res;
                n=num;
                n++;
            }
            else if(s=="i--"){
                num==n? res++ :res;
                n=num;
                n--;
            }
            else if(s=="++i"){
                ++n;
                num==n ? res++ :res;
                n=num;
            }
            else{
                --n;
                num==n ? res++: res;
                n=num;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
