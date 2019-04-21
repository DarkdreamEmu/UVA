#include "bits/stdc++.h"
using namespace std;

vector <int> g[2300];
int vis[2300];
int test=1;

struct node{
	long double u,v,w;
};

int n;
vector<node>vec;
vector< int >top;

long double area(long double x1, long double y1, long double x2, long double y2, long double x3, long double y3){
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

void dfs1(int u){
	vis[u]=test;
	for(int i=0; i<g[u].size(); i++){
		if(vis[g[u][i]]!=test){
			dfs1(g[u][i]);
		}
	}
	top.push_back(u);
}

void dfs2(int u){
	vis[u]=test;
	for(int i=0; i<g[u].size(); i++){
		if(vis[g[u][i]]!=test){
			dfs2(g[u][i]);
		}
	}
}

void clear(){
	for(int i=0; i<2300; i++){
		g[i].clear();
	}
	vec.clear();
	top.clear();
}

int main(){
	int t;
	cin>>t;
	while(t--){
		clear();
		cin>>n;
		for(int i=0; i<n; i++){
			long double u,v,w;
			cin>>u>>v>>w;
			vec.push_back(node{u,v,w});
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i==j)continue;
				else{
					/*long  double x = vec[i].u,y=vec[i].v,z=vec[i].w;
					long double e1 = vec[j].u, e2=vec[j].v; 
					
					long double a1 = x + (0.5)*z, a2 = y + (0.5)*z; //p4 (A)
					long double b1 = x + (0.5)*z, b2 = y - (0.5)*z; //p2 (B)
					long double c1 = x - (0.5)*z, c2 = y - (0.5)*z; //p1 (q)
					long double d1 = x - (0.5)*z, d2 = y + (0.5)*z; //p3 (p)
					
					long double areaofSquare = area(a1,a2,b1,b2,c1,c2)+area(a1,a2,d1,d2,c1,c2);
					
					long double areaofTriangles = 0;
					areaofTriangles += area(e1,e2,a1,a2,b1,b2);
					areaofTriangles += area(e1,e2,b1,b2,c1,c2);
					areaofTriangles += area(e1,e2,c1,c2,d1,d2);
					areaofTriangles += area(e1,e2,a1,a2,d1,d2);
					cout<<"Here "<<s1<<" "<<s2<<" "<<r1<<" "<<r2<<" "<<q1<<" "<<q2<<" "<<p1<<" "<<p2<<endl;
					cout<<areaofTriangles<<" "<<areaofSquare<<" "<<i<<" "<<j<< " "<<(areaofSquare==areaofTriangles)<<endl;*/
					
					int r = vec[i].w/2;
					if(abs(vec[j].u-vec[i].u)<=r && abs(vec[j].v-vec[i].v)<=r ){
						g[i].push_back(j);
		
					}
					/*if(areaofSquare==areaofTriangles){
						g[i].push_back(j);
					}*/
				}
			}
		}
		for(int i=0; i<n; i++){
			if(vis[i]!=test){
				dfs1(i);
			}
		}
		int cnt = 0;
		test++;
		for(int i=top.size()-1; i>=0; i--){
			if(vis[top[i]]!=test){
				dfs2(top[i]);
				cnt++;
			}
		}
		printf("%d\n",cnt);
		test++;
	}
	return 0;
}
