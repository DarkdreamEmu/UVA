#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)&&n){
        if(n%2||n<4){
            printf("Impossible\n");
        }
        else{
            int res=(n*3)/2;
            printf("%d\n",res);
            int i;
            for(i=1; i<n; i++){
                printf("%d %d\n",i,i+1);
                if(i<=n/2){
                    printf("%d %d\n",i,n/2+i);
                }
            }
            printf("%d 1\n",n);
        }
    }
    return 0;
}
