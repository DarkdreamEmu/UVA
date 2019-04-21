#include <bits/stdc++.h>
using namespace std;

static char s[256];
static char pn[256],ss[256];
static char take[256];
static char res[256];

int main(){
    int t;
    scanf("%d",&t);
    getchar();
    getchar();

    for(int k=0; k<t; k++){
        if(k){
            printf("\n");
        }
        gets(pn);
        gets(ss);

        for(int i=0; i<256; i++){
            take[i]=i;
        }
        for(int i=0; pn[i]; i++){
            take[pn[i]]=ss[i];
        }
        puts(ss);
        puts(pn);

        while(gets(s)&&strlen(s)){
            int sz=strlen(s);
            memset(res, 0, sizeof res);
            for(int i=0; i<sz; i++){
                res[i]=take[s[i]];
            }
            puts(res);
        }
    }
    return 0;
}
