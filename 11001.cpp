#include <bits/stdc++.h>
using namespace std;

int main(){
    int v,vo;
    while(scanf("%d%d",&v,&vo)&&(v+vo)){
        double d=0,l,mxl=0;
        int res=0;
        for(int i=1; ; i++){
            double V=(double)v/i;
            if(V<=vo){
                break;
            }
            d=0.3d * sqrt(V - vo);
            l=i*d;
            if(l >= mxl) {
                if(fabs(l - mxl) < 1e-12) {
                    mxl = 0;
                    res = 0;
                    break;
                }
                mxl = l;
                res = i;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
