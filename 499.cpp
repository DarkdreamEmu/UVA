#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int i;
    int freq[52];
    string s;
    getchar();
    while(getline(cin,s))
    {
        for(i=0; i<52; i++)freq[i]=0;
        int l=s.size();
        for(i=0; i<l; i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                freq[s[i]-'a'+26]++;
            }
            else if(s[i]>='A'&&s[i]<='Z')
            {
                freq[s[i]-'A']++;
            }
        }
        int m=-1;
        for(i=0; i<52; i++)
        {
            m=max(m,freq[i]);
        }

        for(i=0; i<52; i++)
        {
            if(freq[i]==m)
            {
                if(i<26)printf("%c",'A'+i);
                else printf("%c",'a'+i-26);
            }
        }
        printf(" %d\n",m);
    }
    return 0;
}
