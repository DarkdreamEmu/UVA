#include <bits/stdc++.h>
using namespace std;

struct coor{
    double x;
    double y;
    double dis1;
    double dis2;
};

double dis(double x1,double y1,double x2,double y2){
    double x=(x2-x1)*(x2-x1);
    double y=(y2-y1)*(y2-y1);
    double res=sqrt(x+y);
    return res;
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    double gx,gy,dx,dy;
    while(scanf("%d %lf %lf %lf %lf",&n,&gx,&gy,&dx,&dy)==5){
        coor take[1010];

        for(int i=0; i<n; i++){
            double x,y;
            scanf("%lf %lf",&x,&y);
            take[i].x=x;
            take[i].y=y;
            take[i].dis1=4*(dis(gx,gy,x,y));
            take[i].dis2=2*(dis(dx,dy,x,y));
        }
        bool ok=false;
        double p1,p2;
        for(int i=0; i<n; i++){
           if(take[i].dis1<=take[i].dis2){
                ok=true;
                p1=take[i].x;
                p2=take[i].y;
                break;
            }
           // cout<<take[i].x<<" "<<take[i].y<<" "<<take[i].dis1<<" "<<take[i].dis2<<endl;
        }
        if(ok){
            printf("The gopher can escape through the hole at (%.3f,%.3f).\n",p1,p2);
        }
        else{
            printf("The gopher cannot escape.\n");
        }
    }
    return 0;
}
