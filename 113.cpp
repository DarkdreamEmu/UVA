#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n,p;
    while(cin>>n>>p)
    {
        double result=pow(p,1/n);
        printf("%.0lf\n",result);
    }
    return 0;
}
