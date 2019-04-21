#include <bits/stdc++.h>
using namespace std;

vector<int> v[1010];

void pre()
{
    v[0].push_back(1);

    for(int i=1;i<=1001;i++)
    {
        long long int carry=0,s;

        for(int j=0;j<v[i-1].size();j++)
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
    int n;
    pre();
    while(scanf("%d",&n)==1){
        printf("%d!\n",n);
        int sz=v[n].size();
        for(int i=sz-1; i>=0; i--){
            int ta=v[n][i];
            printf("%d",ta);
        }
        printf("\n");
    }
    return 0;
}
