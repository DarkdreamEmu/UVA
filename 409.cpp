#include <bits/stdc++.h>
using namespace std;

#define mzx 5000
string word[mzx];
string str[mzx];
int n,k;

int check(string a)
{
    for(int i=0; i<n; i++)
    {
        if(a==word[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int c=1;
    int a[mzx];
    string tmp;
    while(scanf("%d%d",&n,&k)==2)
    {
        //getchar();
        memset(a,0,sizeof(a));
        for(int i=0; i<n; i++)
        {
            cin>>word[i];
        }
        int mx=0;
        int l;
        cin.ignore();
        for(int i=0; i<k; i++)
        {
            getline(cin,str[i]);
            l=str[i].size();

            for(int j=0; j<l; j++)
            {
                tmp="";
                while(isalpha(str[i][j]))
                {
                    if(str[i][j]>='a'&&str[i][j]<='z')
                    {
                        tmp+=str[i][j];
                    }
                    else
                    {
                        tmp+=tolower(str[i][j]);
                    }
                    j++;
                }
                if(check(tmp)==1)
                {
                    a[i]++;
                }
            }
            if(a[i]>mx)
            {
                mx=a[i];
            }
        }
        printf("Excuse Set #%d\n",c++);
        for(int i=0; i<k; i++)
        {
            if(a[i]==mx)
            {
                cout<<str[i]<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
