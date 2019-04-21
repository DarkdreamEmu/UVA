#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string s1,s2;
    while(getline(cin,s1)&&getline(cin,s2))
    {
        int l1=s1.size();
        int l2=s2.size();

        int a[26];
        int b[26];

        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));

        for(int i=0; i<l1; i++)
        {
            a[s1[i]-97]++;
        }
        for(int i=0; i<l2; i++)
        {
            b[s2[i]-97]++;
        }

        for(int i=0; i<26; i++)
        {
            for(int j=min(a[i],b[i])-1; j>=0; j--)
            {
                printf("%c",i+97);
            }
        }
        printf("\n");

    }
    return 0;
}
