#include "bits/stdc++.h"
using namespace std;

#define MAX 300005
#define LL long long
LL ar[MAX];
vector< pair<LL,LL> >chunk[1000];
LL n,m,u,Block;

bool cmp(pair<LL,LL>a, pair<LL,LL>b){
	return a.first<b.first;
}

int main(){
	scanf("%lld %lld %lld",&n,&m,&u);
	Block=sqrt(n);
	for(int i=0; i<n; i++){
		scanf("%lld",&ar[i]);
		chunk[i/Block].push_back( make_pair(ar[i],i));
	}
	LL totBlock = Block+1;
	for(int i=0; i<totBlock; i++){
		sort(chunk[i].begin(),chunk[i].end(),cmp);
	}
	while(m--){
		LL left,right,value,pos;
		scanf("%lld %lld %lld %lld",&left,&right,&value,&pos);
		left--;
		right--;
		pos--;

		int leftBlock = left/Block;
		int rightBlock = right/Block;
		int greaterThan = 0;
		if(leftBlock==rightBlock){
			for(int i=left; i<=right; i++){
				if(ar[i]<value)greaterThan++;
			}
		}
		else{
			if(left%Block){
				leftBlock++;
	    	}
			int k=left;
			while(k<leftBlock*Block){
				if(ar[k]<value)greaterThan++;
				k++;
			}
			while(k+Block-1<=right){
				int p = k/Block;
				int ind = lower_bound(chunk[p].begin(),chunk[p].end(), make_pair(value,numeric_limits<LL>::min()))-chunk[p].begin();
				greaterThan+=ind;
				k+=Block;
			}
			while(k<=right){
				if(ar[k]<value)greaterThan++;
				k++;
			}
		}
		LL updateValue = (u*greaterThan)/(right-left+1);
		
		int updateBlock = pos/Block;
		ar[pos]=updateValue;
		for(int i=0; i<chunk[updateBlock].size(); i++){
			if(chunk[updateBlock][i].second == pos){
				chunk[updateBlock][i].first = updateValue;
				break;
			}
		}
		sort(chunk[updateBlock].begin(),chunk[updateBlock].end(),cmp);
	}
	for(int i=0; i<n; i++){
		printf("%lld\n",ar[i]);
	}
	return 0;
}
