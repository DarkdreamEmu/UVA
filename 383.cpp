#include <bits/stdc++.h>
using namespace std;

#define mx 500

int main()
{
    //freopen ("input.txt","r",stdin);
    //freopen ("output.txt","w",stdout);
    int t,test=1;
    cin>>t;
    cout<<"SHIPPING ROUTES OUTPUT"<<endl;
    while(t--)
    {
        cout<<endl;
        printf("DATA SET  %d\n", test++);
        cout<<endl;
        int n,m,p;
        cin>>n>>m>>p;
        string a,b;
        for(int i=0; i<n; i++)
        {
            string p;
            cin>>p;
        }
        map<string,vector<string> >graph;
        for(int i=0; i<m; i++)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=0; i<p; i++)
        {
            int siz,ds;
            cin>>siz>>a>>b;
            queue<string>q;
            map<string,int>visited;
            visited[a]=0;
            q.push(a);
            bool ok=false;
            while(!q.empty())
            {
                string u=q.front();
                ds=visited[u];
                q.pop();
                if(u==b)
                {
                    ok=true;
                    break;
                }
                int sz=graph[u].size();
                for(int j=0; j<sz; j++)
                {
                    string v=graph[u][j];
                    if(!visited[v])
                    {
                        q.push(v);
                        visited[v]=ds+1;
                    }
                }
            }
            if(!ok)
            {
                cout<<"NO SHIPMENT POSSIBLE"<<endl;
            }
            else
            {
                printf("$%d\n",siz*ds*100);
            }
        }
    }
    cout<<endl<<"END OF OUTPUT"<<endl;
    return 0;
}
