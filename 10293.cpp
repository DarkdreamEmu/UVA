#include <bits/stdc++.h>
using namespace std;

#define mx 120
int n,num[mx],len;
char line[110];

bool isnotalpha(char ch)
{
    return (ch=='.' || ch=='!' || ch==',' || ch==' ' || ch=='?');
}

void Count()
{
    int n = strlen(line);
    for (int i=0; i<n; i++)
        if (isalpha(line[i])) len++;
        else if (isnotalpha(line[i]))
        {
            num[len]++;
            len = 0;
        }
    if (line[n-1]!='-')
    {
        num[len]++;
        len = 0;
    }
}

int main()
{
    memset(num,0,sizeof(num));
    len = 0;
    while (gets(line))
    {
        if (line[0]!='#')
        {
            Count();
            continue;
        }
        for(int i=1; i<=mx-1; i++)
        {
            if (num[i]) printf("%d %d\n", i, num[i]);
            num[i] = 0;
        }
        len = 0;
        printf("\n");
    }
    return 0;
}
