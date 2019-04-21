#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tcase;
    scanf("%d",&tcase);
    while(tcase--)
    {
        long long int yes[10000],no[10000];
        memset(yes,0,sizeof(yes));
        memset(no,0,sizeof(no));
        int a,b;
        char c;
        long long int answer=0,total;
        scanf("%lld",&total);
        for(int i=0; i<total; i++)
        {
            scanf("%d %d %c",&a,&b,&c);
            if(b==1 && c=='c'){
                yes[a]++;
            }
            else if(b==0 && c=='i'){
                no[a]++;
            }

        }
        for(int j=1; j<10; j++)
        {
            for(int i=j+1; i<=10; i++)
            {
                answer+=(yes[i]*no[j]);


            }
        }
        printf("%lld\n",answer);
    }
    return 0;
}

