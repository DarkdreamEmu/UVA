#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,k;
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        string s;
        cin>>s;
        int sz=s.size();
        int cnt=0;
        int fre[26];
        memset(fre,0,sizeof(fre));
        for(int i=0; i<sz; i++){
            if(fre[s[i]-'A']){
                cnt++;
            }
            fre[s[i]-'A']++;
            if(i-k>=0){
                fre[s[i-k]-'A']--;
            }
        }
        printf("Case %d: %d\n",cs++,cnt);
    }
    return 0;
}
