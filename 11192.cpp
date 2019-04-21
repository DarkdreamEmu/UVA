#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    char s[1200];
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        else
        {
            scanf(" ");
            gets(s);
            int l=strlen(s);
            int p,q;
            p=l/n;
            for(i=1; i<=n; i++)
            {
                q=i*p;
                for(j=q-1; j>=q-p; j--)
                {
                    printf("%c",s[j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
