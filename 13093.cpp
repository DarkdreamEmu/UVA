#include "bits/stdc++.h"
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char M[1100],N[1000];
    while(gets(N)){
        gets(M);
        string s=(string)N;
        string t=(string)M;
        stringstream ss(s);
        string A="",B="";
        string tmp;
        while(ss>>tmp){
            A+=tmp[0];
        }
        ss.clear();
        stringstream sss(t);
        while(sss>>tmp){
            B+=tmp[0];
        }
        if(A==B)puts("yes");
        else puts("no");
    }
    return 0;
}
