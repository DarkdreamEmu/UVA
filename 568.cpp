#include <bits/stdc++.h>
using namespace std;

#define N 10001

vector<long long> v[N];

void pre()
{
    v[0].push_back(1);
    v[1].push_back(1);
    for(int i=2;i<=N;i++)
    {
        long long int carry=0,s;
        int sz=v[i-1].size();
        for(int j=0; j<sz; j++)
        {
            s=v[i-1][j]*i+carry;

            if(s>=10)
            {
                v[i].push_back(s%10);
                carry=s/10;
            }
            else
            {
                v[i].push_back(s);
                carry=0;
            }
        }

        if(carry>0)
        {
            while(carry!=0)
            {
                v[i].push_back(carry%10);
                carry=carry/10;
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    pre();
    int n;
    while(scanf("%d",&n)==1){
       printf("%5d -> ",n);
       int sz=v[n].size();
       for(int i=0; i<sz; i++){
            if(v[n][i]!=0){
                printf("%d\n",v[n][i]);
                break;
            }
       }
    }
    return 0;
}

