#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string l="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            char a,b;
            cin>>a>>b;
            for(int j=0; j<26; j++)
            {
                if(l[j]==b)
                {
                    l[j]=a;
                }
            }
        }
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='_')
            {
                cout<<s[i];
            }
            else
            {
                cout<<l[s[i]-65];
            }
        }
        cout<<endl;
    }
    return 0;
}
