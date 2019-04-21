#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n,a=0,b=0,c=0,d=0,e=0,f=0,flag=0;
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        char s[76];
        cin.getline(s,76);
        int l=strlen(s);
        for(i=0; i<l; i++)
        {
            if(s[i]=='S')
            {
                a++;
                break;
            }
            else if(s[i]=='G')
            {
                b++;
                break;
            }
            else if(s[i]=='I')
            {
                c++;
                break;
            }
            else if(s[i]=='F')
            {
                d++;
                break;
            }
            else if(s[i]=='T')
            {
                e++;
                break;
            }
            else if(s[i]=='E')
            {
                f++;
                break;
            }
        }
    }
    if(f>0)
    {
        printf("England %d\n",f);
    }
    if(d>0)
    {
        printf("France %d\n",d);
    }
    if(b>0)
    {
        printf("Germany %d\n",b);
    }
    if(c>0)
    {
        printf("Italy %d\n",c);
    }
    if(a>0)
    {
        printf("Spain %d\n",a);
    }
    if(e>0)
    {
        printf("Turkey %d\n",e);
    }
    return 0;
}
