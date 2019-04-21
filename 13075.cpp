#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        string tmp="";
        for(int i=0; i<a; i++)
        {
            tmp+='C';
        }
        for(int j=0; j<b; j++)
        {
            tmp+='V';
        }
        vector<string>res;

        do
        {
            res.push_back(tmp);
        }
        while(std::next_permutation(tmp.begin(),tmp.end()));

        for(int i=0; i<res.size(); i++)
        {
            cout<<res[i];
            if(i<res.size()-1)
            {
                cout<<" ";
            }
        }
        cout<<endl;
        res.clear();
    }
    return 0;
}
