#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c=1;

    while(cin>>n)
    {
        string a;
        int freq[26];
        int count=0;
        for(int i=0; i<n; i++)
        {
            memset(freq,0,sizeof(freq));
            cin>>a;
            for(int j=0; j<a.size(); j++)
            {
                freq[a[j]-'a']++;
            }
            set<int>check;
            check.empty();
            int c=0;
            for(int k=0; k<26; k++)
            {
                if(freq[k]!=0)
                {
                    check.insert(freq[k]);
                    c++;
                }
            }
            if((check.size()==c)&&check.size()>1)
            {
                count++;
            }
        }
        printf("Case %d: %d\n",c++,count);
    }
    return 0;
}
