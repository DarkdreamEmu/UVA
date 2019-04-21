#include <bits/stdc++.h>
using namespace std;

const int mx=10100;
double xx[mx];
double yy[mx];

double dis(int a,int b){
    double x=xx[b]-xx[a];
    double y=yy[b]-yy[a];
    return sqrt(x*x+y*y);
}

int main(){
    int n;
    while(scanf("%d",&n)&&n){
        for(int i=0; i<n; i++){
            scanf("%lf%lf",&xx[i],&yy[i]);
        }
        //sort(xx,xx+n);
       // sort(yy,yy+n);
        if(n==1){
            printf("INFINITY\n");
            continue ;
        }
        double mn=dis(0,1),res;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                res=dis(i,j);
                if(res<mn){
                    mn=res;
                }
            }
        }
        //mn=sqrt(mn);
        if(mn>=10000.00){
            printf("INFINITY\n");
        }
        else{
            printf("%.4f\n",mn);
        }
    }
    return 0;
}
