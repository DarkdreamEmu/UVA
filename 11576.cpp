#include <bits/stdc++.h>
using namespace std;

int main(){
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        int res=0;
        string str[110];
        for(int i=0; i<m; i++){
            string s;
            cin>>s;
            if(i==0){
                res+=n;
            }
            else{
                bool ok=true;
                for(int j=0; j<n; j++){
                   // cout<<str[i-1][j]<<" "<<s[0]<<endl;
                    if(str[i-1][j]==s[0]){
                        int range=(n-j);
                        string sub1,sub2;
                        sub1=str[i-1].substr(j,range);
                        sub2=s.substr(0,range);
                        if(sub1==sub2){
                            res+=(n-range);
                            ok=false;
                            break;
                        }
                    }
                }
                if(ok){
                    res+=n;
                }
            }
            str[i]=s;
        }
        printf("%d\n",res);
    }
    return 0;
}
