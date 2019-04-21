#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int k;
    while(scanf("%d",&k)!=EOF){
        vector<int>v;
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            v.push_back(a);
        }
        int beg=-1,en=-1,mx=-1,ind=-1;
        for(int i=0; i<n; i++){
            int num=v[i]+k-1;
            vector<int>::iterator up=upper_bound(v.begin(),v.end(),num);
            if(up==v.end()){
                ind=(n-i);
            }
            else{
                ind=(up-v.begin()-i);
            }
            if(ind>mx){
                mx=ind;
                beg=v[i];
                if(up==v.end()){
                    en=v[n-1];
                }
                else{
                    en=v[(up-v.begin())-1];
                }
            }
        }
        printf("%d %d %d\n",mx,beg,en);
    }
    return 0;
}
