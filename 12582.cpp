#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,c=1;
    scanf("%d",&t);
    while(t--){
        char s[100];
        scanf("%s",s);
        int my[26];
        memset(my,0,sizeof(my));
        stack<char>stk;
        stk.push(s[0]);
        stk.push(s[1]);
        for(int i=2; i<strlen(s)-1; i++){
            if(stk.top()==s[i]){
                my[s[i]-'A']++;
                stk.pop();
                my[stk.top()-'A']++;
            }
            else{
                stk.push(s[i]);
            }
        }
        printf("Case %d\n",c++);
        for(int i=0; i<26; i++){
            if(my[i]){
                printf("%c = %d\n",i+'A',my[i]);
            }
        }
    }
    return 0;
}
