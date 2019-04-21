#include <bits/stdc++.h>
using namespace std;

int prime(long long int n)
{
    if(n<2)return 0;
    for(int i=2; i<=n/2; i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}

int rev(long long int n)
{
    long long int r=0;
    while(n!=0)
    {
        r=r*10;
        r+=n%10;
        n=n/10;
    }
    return r;
}

int main()
{
    long long int n;
    while(1)
    {
        cin>>n;
        cout<<n*2<<endl;
        if(rev(n)==n)
        {
            if(prime(rev(n)))
            {
                 break;
            }
        }
    }
    return 0;
}
