#include <bits/stdc++.h>
using namespace std;

bool uni(int n1,int n2){
    int fre[10];
    memset(fre,0,sizeof(fre));
    while(n1>0){
        int tem=n1%10;
        fre[tem]++;
        n1/=10;
    }
    while(n2>0){
        int tem=n2%10;
        fre[tem]++;
        n2/=10;
    }
    for(int i=1; i<=9; i++){
        if(!fre[i]||fre[i]>1){
            return false;
        }
    }
    return true;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    bool ok=false;
    while(scanf("%d",&N)&&N){
        if(ok){
            printf("\n");
        }
        ok=true;
        bool check=false;
        for(int i=1234; i<=98765/N; i++){
            int num=(i*N);
            bool flag=(i<10000);
            if(uni(num,i)){
                printf("%0.5d / %0.5d = %d\n",num,i,N);
                check=true;
            }
        }
        if(!check){
            printf("There are no solutions for %d.\n",N);
        }
    }
    return 0;
}
