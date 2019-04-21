#include "bits/stdc++.h"
using namespace std;

double p, q, r, s, t ,u;

double fun(double value){

    double res=p*exp(-value)+q*sin(value)+r*cos(value)+s*tan(value)+t*value*value+u;
    return res;
}

double ans_me(){
    double low=0.0;
    double high=1.0,mid;
    while(low+1e-7<high){
        mid=(high+low)/2.0;
        if(fun(low)*fun(mid)<=0){
            high=mid;
        }
        else{
            low=mid;
        }
    }
    return mid;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)==6){
        double res=ans_me();
        if(fun(0)*fun(1)>0)puts("No solution");
        else printf("%.4f\n",res);
    }
    return 0;
}
