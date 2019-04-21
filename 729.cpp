#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int m,n;
        scanf("%d%d",&m,&n);
        string tak="";
        for(int i=0; i<m; i++){
            if(i<m-n){
                tak+='0';
            }
            else{
            	tak+='1';
            }
        }
        vector<string>res;
        do{
            res.push_back(tak);
        }while(next_permutation(tak.begin(),tak.end()));

        sort(res.begin(),res.end());
        for(int i=0; i<res.size(); i++){
            cout<<res[i]<<endl;
        }
        if(t){
            printf("\n");
        }
    }
    return 0;
}
