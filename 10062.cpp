#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[1001];
    int k=0;
    int asci[130];
    while(gets(s))
    {
        memset(asci,0,sizeof(asci));

        int l=strlen(s);
        if(k!=0)
        {
            printf("\n");
        }
        for(int i=32; i<=127; i++)
        {
            int count=0;
            for(int j=0; j<l; j++)
            {
                if(s[j]==i)
                {
                    count++;
                }
            }
            asci[i]=count;
        }
        int max=0;
        for(int i=32; i<=127; i++)
        {
            if(asci[i]>max)
            {
                max=asci[i];
            }
        }
        for(int i=1; i<=max; i++)
        {
            for(int j=127; j>=32; j--)
            {
                if(asci[j]==i)
                {
                    printf("%d %d\n",j,i);
                }
            }
        }
        k=1;
    }
    return 0;
}
