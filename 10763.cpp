#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n&&n)
    {
        int st[n];
        int ed[n];

        memset(st,0,sizeof(st));
        memset(ed,0,sizeof(ed));

        for(int i=0; i<n; i++)
        {
            cin>>st[i]>>ed[i];
        }

        sort(st,st+n);
        sort(ed,ed+n);

        bool ok=true;
        for(int i=0; i<n; i++)
        {
            if(st[i]==ed[i])
            {
                ok=true;
            }
            else
            {
                ok=false;
                break;
            }
        }

        if(ok)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
