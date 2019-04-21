#include <bits/stdc++.h>
using namespace std;

vector<int>my[300];

int main(){
    char s[1111110];
    gets(s);
        for(int i=0; i<300; i++){
            my[i].clear();
        }
        int sz=strlen(s);
        for(int i=0; i<sz; i++){
            my[s[i]].push_back(i);
        }
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            string str;
            cin>>str;
            int ind=-1,first=0;
            bool ok=true;
            for(int j=0; j<str.size(); j++){
                vector< int >::iterator up=upper_bound( my[str[j]].begin(),my[str[j]].end(),ind);
                ind=up-my[str[j]].begin();
                if(up==my[str[j]].end()){
                    ok=false;
                }
                ind=my[str[j]][ind];
                if(j==0){
                    first=ind;
                }
            }
            if(ok){
                printf("Matched %d %d\n",first,ind);
            }
            else{
                printf("Not matched\n");
            }
        }
    return 0;
}
