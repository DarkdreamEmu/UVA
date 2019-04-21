#include "bits/stdc++.h"
using namespace std;

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n;
        cin>>n;
        int sx=-1000000,sy=-1000000,fx=100000,fy=1000000;
        bool ok=1;
        int ans;
        while(n--){
            int X1,Y1,X2,Y2;
            cin>>X1 >> Y1>> X2>>Y2;
            sx=max(sx,X1),sy=max(sy,Y1);
            fy=min(fy,Y2),fx=min(fx,X2);
            if (sx>=fx || sy>=fy) ok=0;
        }
        if(!ok)ans=0;
        else ans=(fx-sx)*(fy-sy);
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
