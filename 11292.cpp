#include <bits/stdc++.h>
using namespace std;

int visited[100000];

int main()
{
    int n,m;
    while(cin>>n>>m&&n+m)
    {
        int dragon[n];
        int knights[m];

        memset(dragon,0,sizeof(dragon));
        memset(knights,0,sizeof(knights));
        memset(visited,0,sizeof(visited));

        for(int i=0; i<n; i++)
        {
            cin>>dragon[i];
        }
        for(int i=0; i<m; i++)
        {
            cin>>knights[i];
        }
        sort(dragon,dragon+n);
        sort(knights,knights+m);

        int res=0;
        int cnt=0;
        if(m<n)
        {
            cout<<"Loowater is doomed!"<<endl;
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                bool ok=false;
                for(int j=0; j<m; j++)
                {
                    if(!visited[j])
                    {
                        if(dragon[i]<=knights[j])
                        {
                            res+=knights[j];
                            cnt++;
                            visited[j]=1;
                            ok=true;
                        }
                    }
                    if(ok)
                    {
                        break;
                    }
                }
            }
            if(cnt==n)
            {
                cout<<res<<endl;
            }
            else
            {
                cout<<"Loowater is doomed!"<<endl;

            }
        }
    }
    return 0;
}
