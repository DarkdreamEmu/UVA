#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int res=10000000;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i*j>n)break;
                else
                for(int k=1; k<=n; k++){
                    if(i*j*k==n)
                        res=min(res,2*(i*j+j*k+k*i));
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
