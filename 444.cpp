#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        int l=s.size();
        if(isalpha(s[0]))
        {
            for(int i=l-1; i>=0; i--)
            {

                int r=s[i];
                int p=0;
                while(r!=0)
                {
                    p=r%10;
                    printf("%d",p);
                    r=r/10;
                }

            }
            printf("\n");
        }
        else
        {
            int range;
            int val;
            for(int i=l-1; i>=0; )
            {
                val=0;
                if(s[i]=='1')
                {
                    range=3;
                }
                else
                {
                    range=2;
                }

                for(int j=1; j<=range; j++)
                {
                    val=val*10+s[i]-'0';
                    i--;
                }
                printf("%c",val);
            }
            printf("\n");
        }
    }
    return 0;
}
