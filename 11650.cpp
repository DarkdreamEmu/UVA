#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int h,m;
        scanf("%d:%d", &h,&m);
        h=(11-h)+(m==0);
        if(h<=0){
            h=h+12;
        }
        if(m!=0){
            m=60-m;
        }
        printf("%02d:%02d\n",h,m);
    }
    return 0;
}
