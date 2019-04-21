#include <bits/stdc++.h>
using namespace std;

struct node{
    char ch;
    int row;
    int col;
};

int main(){
    int n;
    while(scanf("%d",&n)==1){
        stack<node>stkkkk;
        vector<node>v;
        for(int i=0; i<n; i++){
            char ch;
            int r,c;
            scanf(" %c %d %d",&ch,&r,&c);
            node temp;
            temp.ch=ch;
            temp.row=r;
            temp.col=c;
            stkkkk.push(temp);
            v.push_back(temp);
        }
        string s;
        while(cin>>s){
            stack<node>stk;
            stk=stkkkk;
            long long sum=0;
            int sz=s.size();
            if(sz==1){
                puts("0");
                continue;
            }
            bool ok=true;
            for(int i=0; i<sz; i++){
                if(s[i]==')'){
                    node num1,num2;
                    num1=stk.top();
                    stk.pop();
                    num2=stk.top();
                    stk.pop();
                    if(num2.col==num1.row){
                        sum+=(num2.row*num2.col*num1.col);
                        node p;
                        p.ch='a';
                        p.row=num2.row;
                        p.col=num1.col;
                        stk.push(p);
                    }
                    else{
                        ok=false;
                        break;
                    }
                }
                else if(isalpha(s[i])){
                    for(int j=0; j<n; j++){
                        if(v[j].ch==s[i]){
                            node temp;
                            temp.ch=s[i];
                            temp.row=v[j].row;
                            temp.col=v[j].col;
                            stk.push(temp);
                            break;
                        }
                    }
                }
            }
            if(ok){
                printf("%lld\n",sum);
            }
            else{
                puts("error");
            }
        }
    }
    return 0;
}
