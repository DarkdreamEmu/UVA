#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        vector<string>first;
        set<string>my;
        first.clear();
        my.clear();
        char s[1000000];
        gets(s);
        for(int i=0; i<n; i++){
            gets(s);
            string ss=string(s);
            first.push_back(ss);
        }
        for(int i=0; i<m; i++){
            gets(s);
            string ss=string(s);
            for(int j=0; j<n; j++){
                string tem=first[j]+ss;
                my.insert(tem);
            }
        }
        printf("Case %d: ",cs++);
        cout<<my.size()<<endl;
    }
    return 0;
}
