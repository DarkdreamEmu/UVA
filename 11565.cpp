#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        bool ok=true;
        for(int i=-100; i<=100&&ok; i++){
            for(int j=-100; j<=100&&ok; j++){
                for(int k=-100; k<=100&ok; k++){
                    if(i!=j&&j!=k&&k!=i&&i+j+k==a&& i*j*k == b && i*i+j*j+k*k == c){
                        printf("%d %d %d\n",i,j,k);
                        ok=false;
                    }
                }
            }
        }
        if(ok){
            printf("No solution.\n");
        }
    }
    return 0;
}
