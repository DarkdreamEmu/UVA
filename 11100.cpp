#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)&&n){
        vector<int>v;
        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        int mx=0,k=0,cnt=1;
        for(int i=0; i<n; i++){
            if(v[i]==v[i-1]){
                cnt++;
            }
            else{
                mx=max(cnt,mx);
                cnt=1;
            }
        }
        mx=max(mx,cnt);
        printf("%d\n",mx);

        for(int i=0; i<mx; i++) {
			int first = 1;
			for(int j=i; j<n; j+=mx) {
				if(!first) printf(" ");
				printf("%d",v[j]);
				if(first) first = 0;
			}
			printf("\n");
		}
    }
    return 0;
}
