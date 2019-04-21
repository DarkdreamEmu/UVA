#include <bits/stdc++.h>
using namespace std;

#define mx 100000
#define inf 1000000

vector<int>graph[mx];
bool visited[mx];
int dis[mx];
map<string,int>indexing;
map<int,string>resulting;
int source;

void clean(){
    for(int i=0; i<mx; i++){
        graph[i].clear();
    }
    indexing.clear();
}

void bfs(int s){
	memset(visited,0,sizeof(visited));
	memset(dis,-1,sizeof(dis));
    queue<int>q;
    visited[s]=1;
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int sz=graph[u].size();
        //cout<<graph[u].size()<<endl;
        for(int i=0; i<sz; i++){
            int x=graph[u][i];
            if(!visited[x]){
                visited[x]=1;
                dis[x]=dis[u]+1;
                q.push(x);
            }
        }
    }
}

void input_format(int n){
    int ind=1;
    cin.ignore();
    while(n--){
        vector<string>temp;
        vector<string>extra;
        vector<string>f;
        string s;
        getline(cin,s);
        int sima=s.find(':');
        string clone=s.substr(0,sima);
        //cout<<clone<<endl;
        stringstream ss(clone);
        int cnt=0;
        string take;
        while(ss>>take){
            if(cnt%2==0){
                temp.push_back(take);
            }
            else{
                extra.push_back(take);
            }
            cnt++;
            //cout<<take<<endl;
        }
        int sz=temp.size();
        string make;
        string space=" ";
        for(int i=0; i<sz; i++){
            make=temp[i]+extra[i];
            int sss=make.size();
            if(make[sss-1]==','){
            	make.erase(sss-1);
			}
			//cout<<make<<endl;
            f.push_back(make);
            if(!indexing[make]){
                indexing[make]=ind++;
                if(make=="Erdos,P."){
                    source=ind-1;
                }
            }
           // cout<<indexing[make]<<endl;
        }
        for(int i=0; i<sz; i++){
            for(int j=i+1; j<sz; j++){
                int u=indexing[f[i]];
                int v=indexing[f[j]];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        temp.clear();
        extra.clear();
        f.clear();
    }
}


int main(){
    //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int p,n;
        scanf("%d%d",&p,&n);
        clean();
        input_format(p);
        bfs(source);
        printf("Scenario %d\n",cs++);
        for(int i=0; i<n; i++){
            string in;
            getline(cin,in);
            string pri=in;
            in.erase(std::remove(in.begin(), in.end(), ' '), in.end());
            int des=indexing[in];
            //cout<<source<<" "<<des<<endl;
            //cout<<in<<endl;
            cout<<pri;
            if(indexing.find(in)==indexing.end()){
            	printf(" infinity\n");
			}
            else if(dis[des]==-1){
                printf(" infinity\n");
            }
            else{
                printf(" %d\n",dis[des]);
            }
            //cout<<dis[des]<<endl;
        }
    }
    return 0;
}
