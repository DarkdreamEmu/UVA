#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>

using namespace std;


int main()
{

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int test;
    cin>>test;
    vector <pair<int,string> > vi;
    int in;
    string ss;
    char str[100];
    getchar();
    for(int cas=1; cas<=test; cas++)
    {

        getchar();


        string a,b;
        vi.clear();
        getline (cin,a);
        getline (cin,b);
        stringstream x (a);
        stringstream y(b);
        while(x>>in)
        {
            y>>ss;
            vi.push_back(make_pair(in,ss));

        }

        sort(vi.begin(),vi.end());


        if(cas>1) printf("\n");
        for(int i=0; i<vi.size(); i++)     cout<<vi[i].second<<endl;

    }



    return 0;
}
