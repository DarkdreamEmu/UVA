#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
using namespace std;

#define max 2002
int mark[max];

void sieve()
{
    int i,j;
    mark[2]=0;
    mark[1]=mark[0]=1;
    for(i=4; i<=max; i+=2)mark[i]=1;
    for(i=3; i*i<=max; i+=2)
    {
        if(!mark[i])
        {
            for(j=i*i; j<=max; j+=i*2)
            {
                mark[j]=1;
            }
        }
    }
}

int main()
{
    int i,t,test=1;
    sieve();
    char s[2002];
    scanf("%d",&t);
    while(t--)
    {
        int arr[128]={};
        scanf("%s",&s);
        int l=strlen(s);
        for(i=0; i<l; i++)
        {
            arr[s[i]]++;
        }
        int c=0,g;
        printf("Case %d: ",test);
        for(i=0; i<128; i++)
        {
            if(mark[arr[i]]!=1)
            {
                printf("%c",i);
                c++;
            }
        }
        if(c==0)
        {
            printf("empty");
        }
        test++;
        puts("");
    }
    return 0;
}
