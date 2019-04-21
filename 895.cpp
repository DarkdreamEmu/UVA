#include <bits/stdc++.h>
using namespace std;

vector<string>v;
int result;

int check(string s1)
{
    int freq[26];
    result=0;
    for(int i=0; i<v.size(); i++)
    {
        int l=v[i].size();
        memset(freq,0,sizeof(freq));
        for(int j=0; j<l; j++)
        {
            freq[v[i][j]-'a']++;
        }
        int count=0;
        for(int k=0; k<s1.size(); k++)
        {
            if(freq[s1[k]-'a'])
            {
                count++;
                freq[s1[k]-'a']--;
            }
        }
        //cout<<l<<" "<<count<<endl;
        if(v[i].size()==count)
        {
            result++;
        }
    }
    return result;
}


int main()
{
    string a;
    while(cin>>a,a[0]!='#')
    {
        v.push_back(a);
    }
    string b;
    cin.ignore();
    while(getline(cin,b)&&b[0]!='#')
    {
        int t=b.size();
        //cout<<t<<endl;
        string tmp="";
        for(int i=0; i<t; i++)
        {
            if(b[i]>='a'&&b[i]<='z')
            {
                tmp+=b[i];
            }
        }
        //cout<<tmp<<endl;
        int result=check(tmp);
        printf("%d\n",result);
    }
    v.clear();
    return 0;
}
