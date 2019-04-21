#include "bits/stdc++.h"
using namespace std;


#define MX 1001

vector<int>g[MX];
int Articulation_Bridge[MX][MX],Already[MX][MX];
int Visited[MX],Discover[MX],Low[MX],parent[MX],tme=0;
vector< pair<int,int> >ans;

void clear(){
    tme=0;
    ans.clear();
	for(int i=0; i<MX; i++){
		Visited[i]=Discover[i]=Low[i]=0;
		parent[i]=-1;
		g[i].clear();
	}
	memset(Articulation_Bridge,0,sizeof(Articulation_Bridge));
    memset(Already,0,sizeof(Already));
}

void AB(int u){
	Visited[u]=1;
	Discover[u]=Low[u]=++tme;
	int child=0;
	for(int i=0; i<g[u].size(); i++){
		int v=g[u][i];
		 if(!Visited[v]){
			child++;
			parent[v]=u;
			AB(v);
			Low[u]=min(Low[u],Low[v]);
		    if(Discover[u]<Low[v]){
				Articulation_Bridge[u][v]=Articulation_Bridge[v][u]=1;
			}
		}
		else if(v!=parent[u]){
		    Low[u]=min(Low[u],Low[v]);
		}
	}
}

void dfs(int u){
	Visited[u]=1;
	for(int i=0; i<g[u].size(); i++){
		int v=g[u][i];
		if(!Visited[v]){
		    parent[v]=u;
		    if(Articulation_Bridge[u][v] && !Already[u][v]){
				ans.push_back(make_pair(u,v));
				ans.push_back(make_pair(v,u));
				Already[u][v]=Already[v][u]=1;
			}
			else if(!Already[u][v]){
				ans.push_back(make_pair(u,v));
				Already[u][v]=Already[v][u]=1;
			}
			dfs(v);

		}
		else if(Visited[v]){
			if(parent[u]!=v){
				if(Articulation_Bridge[u][v] && !Already[u][v]){
				ans.push_back(make_pair(u,v));
				ans.push_back(make_pair(v,u));
				Already[u][v]=Already[v][u]=1;
			}
			else if(!Already[u][v]){
				ans.push_back(make_pair(u,v));
				Already[u][v]=Already[v][u]=1;
			}
			}
		}

	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m;
	int cs=1;
	while(scanf("%d %d",&n,&m) && (n+m)){
		clear();
		for(int i=0; i<m; i++){
			int u,v;
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		printf("%d\n\n",cs++);
		AB(1);
		memset(Visited,0,sizeof(Visited));
		memset(parent,-1,sizeof(parent));
		dfs(1);
		for(int i=0; i<ans.size(); i++){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
		printf("#\n");
	}
	return 0;
}
