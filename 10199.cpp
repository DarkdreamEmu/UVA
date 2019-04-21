#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

const int MAX=110;
bool vis[MAX];
bool AP[MAX];
int parent[MAX];
int low[MAX];
int disc[MAX];
vector<int>graph[MAX];
int tim;
map<string,int>my;
map<int,string>stor;
int res=0;
vector<string>ans;

void intialization(){
    for(int i=0; i<MAX; i++){
        vis[i]=AP[i]=false;
        parent[i]=-1;
        low[i]=0;
        graph[i].clear();
        disc[i]=0;
    }
    tim=0;
    stor.clear();
    my.clear();
    res=0;
    ans.clear();
}

void Articulation_point(int u){
    vis[u]=true;
    low[u]=disc[u]=++tim;
    int child=0;
    int sz=graph[u].size();
    for(int i=0; i<sz; i++){
        int v=graph[u][i];
        if(vis[v]==false){
            child++;
            parent[v]=u;
            Articulation_point(v);
            low[u]=min(low[u],low[v]);

            if((parent[u]!=-1)&&(low[v]>=disc[u])){
                AP[u]=true;
            }
            if(parent[u]==-1&&child>1){
                AP[u]=true;
            }
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],disc[v]);
        }
    }
}

int main(){
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,cs=1;
    bool ok=false;
    while(scanf("%d",&n)&&n){
        intialization();
        for(int i=1; i<=n; i++){
            string s;
            cin>>s;
            my[s]=i;
            stor[i]=s;
        }
        int m;
        scanf("%d",&m);
        for(int i=0; i<m; i++){
            string str1,str2;
            cin>>str1>>str2;
            int u=my[str1];
            int v=my[str2];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                Articulation_point(i);
            }
        }
        for(int i=1; i<=n; i++){
            if(AP[i]){
                res++;
                ans.push_back(stor[i]);
            }
        }
        if(ok){
            printf("\n");
        }
        ok=true;
        printf("City map #%d: %d camera(s) found\n",cs++,res);
        sort(ans.begin(),ans.end());
        for(int i=0; i<res; i++){
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}

