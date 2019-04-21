#include <bits/stdc++.h>
using namespace std;

vector<int>res[110];
int num,n;
int ar[1110];
int j=0;
map<vector<int>,bool>my;

void backtrack(vector<int>v,int sum,int ind){
    sum+=ar[ind];
    v.push_back(ar[ind]);
    if(sum==num){
    	if(!my[v]){
    		res[j++]=v;
    		my[v]=1;
		}
    }
    for(int i=ind+1; i<n; i++){
        backtrack(v,sum,i);
    }
}

void clean(int f){
	for(int i=0; i<f; i++){
		res[i].clear();
	}
	my.clear();
	j=0;
}

int main(){
    while(scanf("%d%d",&num,&n)&&(num+n)){
        for(int i=0; i<n; i++){
            scanf("%d",&ar[i]);
        }
        for(int i=0; i<n; i++){
            vector<int>v;
            backtrack(v,0,i);
        }
        printf("Sums of %d:\n",num);
        if(j==0){
        	cout<<"NONE"<<endl;
        	continue;
		}
        for(int k=0; k<j; k++){
        	for(int l=0; l<res[k].size(); l++){
        		cout<<res[k][l];
        		if(l<res[k].size()-1){
        			cout<<"+";
				}
			}
			cout<<endl;
		}
		clean(j);
    }
    return 0;
}
