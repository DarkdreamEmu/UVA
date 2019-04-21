#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[26],b[26];
    while(gets(a))
    {
        gets(b);
        int l1=strlen(a);
        int l2=strlen(b);
        int s1=0,s2=0,i;
        for(i=0; i<l1; i++)
        {
            if(a[i]>='a'&&a[i]<='z')
            {
                s1+=a[i]-96;
            }
            else if(a[i]>='A'&&a[i]<='Z')
            {
                s1+=a[i]-64;
            }
        }

        ////////////////////////////////////////////////////

        int su1=0;
        while(s1!=0)
        {
            su1+=s1%10;
            s1/=10;
        }
        if(su1>9)
        {
            s1=su1;
            su1=0;
            while(s1!=0)
            {
                su1+=s1%10;
                s1/=10;
            }
        }

        ////////////////////////////////////////////

         for(i=0; i<l2; i++)
        {
            if(b[i]>='a'&&b[i]<='z')
            {
                s2+=b[i]-96;
            }
            else if(b[i]>='A'&&b[i]<='Z')
            {
                s2+=b[i]-64;
            }
        }

        ////////////////////////////////////////////////////

        int su2=0;
        while(s2!=0)
        {
            su2+=s2%10;
            s2/=10;
        }
        if(su2>9)
        {
            s2=su2;
            su2=0;
            while(s2!=0)
            {
                su2+=s2%10;
                s2/=10;
            }
        }

        /////////////////////////////////////////////////

        float r;
        if(su1>su2)
        r=((float)su2*100/(float)su1);
        else
        r=((float)su1*100/(float)su2);
        printf("%0.2f %%\n",r);
    }
    return 0;
}
