#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[1422];
    int n;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);

        int flag=0,count=0;
        for(int i=1; i<n; i++)
        {
            if(a[i]-a[i-1]>200)
            {
                flag=1;
            }
        }
        if ( 2 * (1422 - a [n - 1]) > 200 )flag=1;
        if(flag==1)
        {
            cout<<"IMPOSSIBLE"<<endl;

        }
        else
        {
            cout<<"POSSIBLE"<<endl;
        }
    }
    return 0;
}
