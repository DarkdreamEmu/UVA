#include <bits/stdc++.h>
using namespace std;

#define mx 25150

map<string,int>my;
map<int,string>res;
vector<int>graph[mx];
bool visited[mx];
int dis[mx];
vector<string>stor;
int parent[mx];

bool check(string a,string b){
	int cnt=0;
	int sz=a.size();
	for(int i=0; i<sz&&cnt<2; i++){
		if(a[i]!=b[i]){
			cnt++;
		}
	}
	return (cnt==1);
}

void clean(){
    my.clear();
    res.clear();
    for(int i=0; i<=10; i++){
        graph[i].clear();
        parent[i]=-1;
    }
}

int bfs(int s,int des){
    memset(visited,0,sizeof(visited));
    memset(parent,-1,sizeof(parent));
    queue<int>q;
    q.push(s);
    dis[s]=0;
    visited[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==des){
            return 1;
        }
        int sz=graph[u].size();
        for(int i=0; i<sz; i++){
            int x=graph[u][i];
            if(!visited[x]){
                parent[x]=u;
                visited[x]=1;
                dis[x]=dis[u]+1;
                q.push(x);
            }
        }
    }
    return 0;
}

void print_path(int d){
    vector<int>path;
    for(int v=d; v!=-1; v=parent[v]){
        path.push_back(v);
    }
    reverse(path.begin(),path.end());
    for(int i=0; i<path.size(); i++){
        cout<<res[path[i]]<<endl;
    }
    path.clear();
    return ;
}

int main(){
    clean();
    string s;
    bool ok=false;
    int ind=1;
    int n=0;
    while(getline(cin,s)){
    	if(s.size()==0){
    		break;
		}
        if(!my[s]){
        	my[s]=ind++;
        	res[ind-1]=s;
        	stor.push_back(s);
		}
    }
    int sz=stor.size();
    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            int x=stor[i].size();
            int y=stor[j].size();
            if(x==y){
                if(check(stor[i],stor[j])){
                    int u=my[stor[i]];
                    int v=my[stor[j]];
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }
    }
    
    string sou,des;
    string in;
    while(getline(cin,in)&&in.size()!=0){
    	if(ok){
    		printf("\n");
		}
		ok=true;
        stringstream ss(in);
        ss>>sou;
        ss>>des;
        int sss=my[sou];
        int ddd=my[des];
        int res=bfs(sss,ddd);
        if(my.find(sou)==my.end()||my.find(des)==my.end()){
        	printf("No solution.\n");
		}
        else if(res){
            print_path(ddd);
        }
        else{
            printf("No solution.\n");
        }
    }
    return 0;
}
