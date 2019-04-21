#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    long len,n,i;
    char s[10000];
    while(gets(s))
    {
        len=strlen(s);
        n=0;
        for(i=len-1; i>=0; i--)
        {
            if(s[i]>='p' && s[i]<='z')
                n++;
            else if(s[i]=='C' || s[i]=='D' || s[i]=='E' || s[i]=='I')
            {
                if(n>=2)
                    n--;
                else
                {
                    n=0;
                    break;
                }
            }
            else if(s[i]=='N')
            {
                if(n<1)
                {
                    n=0;
                    break;
                }
            }
        }
        if(n==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
