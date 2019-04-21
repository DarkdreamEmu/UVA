#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int t;
    int freq[26],max=0;
    memset(freq,0,sizeof(freq));
    scanf("%d",&t);
    for(int i=0; i<=t; i++)
    {
        string s;
        getline(cin,s);

        int l=s.size();

        for(int i=0; i<l; i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                freq[s[i]-32-'A']++;
            }
            else if(s[i]>='A'&&s[i]<='Z')
            {
                freq[s[i]-'A']++;
            }
        }
    }
    for(int i=0; i<=25; i++)
    {
        if(freq[i]>max)
        {
            max=freq[i];
        }
    }
    for(int i=max; i>=1; i--)
    {
        for(int j=0; j<=25; j++)
        {
            if(freq[j]==i)
            {
                printf("%c %d\n",j+65,freq[j]);
            }
        }
    }
    return 0;
}
