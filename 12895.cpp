#include <bits/stdc++.h>
using namespace std;

#define lli long long int
int a[10];

int main()
{

    lli t;
    cin>>t;

    while(t--)
    {
        memset(a,0,sizeof(a));
        lli num,r;
        cin>>num;
        r=num;
        int i=0;
        while(num!=0)
        {
            a[i]=num%10;
            num=num/10;
            i++;
        }
        lli sum=0;
        for(int j=0; j<i; j++)
        {
            sum=sum+(lli)pow(a[j],i);
        }
        if(sum==r)
        {
            cout<<"Armstrong"<<endl;
        }
        else
        {
            cout<<"Not Armstrong"<<endl;
        }
    }
    return 0;
}
