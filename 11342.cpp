#include <bits/stdc++.h>
using namespace std;

#define SWAP(x,y) { int tmp=x; x=y; y=tmp; }

void print(int j,int a,int b){
	if(j>a)
		SWAP(j,a);
	if(j>b)
		SWAP(j,b);
	if(a>b)
		SWAP(a,b);
	printf("%d %d %d\n",j,a,b);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        bool ok=true;
        for(int i=0; i*i<=n; i++){
            int tm=n-(i*i);
            int j=sqrt(double(tm));
            int k=0;
            while(k<=j){
                if(k*k+j*j==tm){
                    print(i,j,k);
                    ok=false;
                    break;
                }
                else if(j*j+k*k>tm){
                    j--;
                }
                else{
                    k++;
                }
            }
            if(!ok){
                break;
            }
        }
        if(ok){
            printf("-1\n");
        }
    }
    return 0;
}
