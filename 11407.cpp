#include <bits/stdc++.h>
using namespace std;

#define N 10000
int dp[N];

void minimum_square()
{
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4; i<=N; i++)
    {
        dp[i]=i;
        for(int x=1; x<=i; x++)
        {
            int tmp=x*x;
            if(tmp>i)
            {
                break;
            }
            else
            {
                dp[i]=min(dp[i],1+dp[i-tmp]);
            }
        }
    }
}

int main()
{
    minimum_square();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
