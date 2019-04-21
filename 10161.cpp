#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)&&n){
        int bas=sqrt(n);
        int c,r;
        if(bas*bas<n){
            bas++;
        }
        if(n>(bas*bas-bas)){
            c=bas;
            r=bas*bas-n+1;
        }
        else{
            r=bas;
            c=n-(bas-1)*(bas-1);
        }
        if(bas%2==0){
            swap(r,c);
        }
        printf("%d %d\n",r,c);
    }
    return 0;
}
