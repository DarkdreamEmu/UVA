#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[150];
    char s[150]="";
    int i,count=0;
    int max=0;
    while(scanf("%s",a))
    {
        if(strcmp(a,"E-N-D")==0)
        {
            break;
        }
        count=0;
        int l=strlen(a);
        for(i=0; i<l; i++)
        {
            if(isalpha(a[i])||a[i]=='-')
            {
                count++;
            }
        }
        if(count>max)
        {
            max=count;
            strcpy(s,a);
        }
    }
    int l1=strlen(s);
    for(i=0; i<l1; i++)
    {
        if(isalpha(s[i]) || s[i]=='-')
        {
            printf("%c",tolower(s[]));
        }
    }
    printf("\n");
    return 0;
}
