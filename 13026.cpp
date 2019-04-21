#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        string lis[100000];
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>lis[i];
        }
        string mom;
        cin>>mom;

        printf("Case %d:\n",test++);
        for(int i=0; i<n; i++)
        {
            string s=lis[i];
            int siz=s.size();

            int cnt=0;
            int k=0;
            for(int j=0; j<siz; j++)
            {
                if(s[j]!=mom[k])
                {
                    cnt++;
                }
                k++;
            }
            if(cnt<=1)
            {
                cout<<s<<endl;
            }
        }
    }
    return 0;
}
