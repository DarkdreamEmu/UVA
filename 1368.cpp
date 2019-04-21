#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,tc,c,w,x,y,z,n,m,u,v,cnt,mx,mn,p,q,r,sum,g,t;
    string s[55],res;
    cin>>tc;
    while(cin>>n>>m)
    {
        res="";
        for(int i=0;i<n;i++)
            cin>>s[i];
        cnt=0;
        for(int i=0;i<m;i++)
        {
            a=c=g=t=0;
            for(int j=0;j<n;j++)
                if(s[j][i]=='A')    a++;
                else if(s[j][i]=='C')    c++;
                else if(s[j][i]=='G')    g++;
                else if(s[j][i]=='T')    t++;
            int mx=max(a,max(c,(max(g,t))));
            cnt+=(n-mx);
            if(mx==a)   res+="A";
            else if(mx==c)   res+="C";
            else if(mx==g)   res+="G";
            else if(mx==t)   res+="T";
        }
        cout<<res<<endl;
        cout<<cnt<<endl;
    }
    return 0;
}
