#include <bits/stdc++.h>
using namespace std;


int main()
{
    int l;
    string s;
    while(cin>>l>>s)
    {
        map<string,int>res;
        for(int i=0; i<s.size()&&i<=s.size()-l; i++)
        {
            string tmp=s.substr(i,l);
            res[tmp]++;
        }
        map<string,int>::iterator it;
        int mx=0;
        string result;
        for(it=res.begin(); it!=res.end(); it++)
        {
            if(it->second>mx)
            {
                mx=it->second;
                result=it->first;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}
