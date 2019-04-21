#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int l=s.size();
        int count=0;
        int sum=0;
        for(int i=0; i<l; i++)
        {
            if(s[i]=='O')
            {
                count++;
                sum+=count;
            }
            else
            {
                count=0;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
