#include<iostream>
#include<cmath>

using namespace std;
int main()
{
    float l,d,h,v,cd,H,t;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>l>>d>>h>>v;
        H=h/1000;
        t=sqrt((2*H)/9.81);
        cd=t*v;
        if((cd>=(d-500) && cd<=(d+500))||(cd>=(d+l-500)&& cd<=(d+l+500)))
            cout<<"EDGE"<<endl;
        else if(cd>=(d+500)&& cd<=(d+l-500))
            cout<<"POOL"<<endl;
        else
            cout<<"FLOOR"<<endl;
    }
    return 0;
}
