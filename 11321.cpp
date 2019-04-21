#include <bits/stdc++.h>
using namespace std;

int n,m;

bool love(int i,int j){
    if(i%m!=j%m){
        return i%m<j%m;
    }
    else{
        if(abs(i)%2==0&&abs(j)%2==0){
            return i<j;
        }
        else if(abs(i)%2==1&&abs(j)%2==1){
            return i>j;
        }
        else if(abs(i)%2==1){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    while(scanf("%d%d",&n,&m)&&(n+m)){
        vector<int>v;
        for(int i=0; i<n; i++){
            int a;
            scanf("%d",&a);
            v.push_back(a);
        }
        sort(v.begin(),v.end(),love);
        printf("%d %d\n",n,m);
        for(int i=0; i<n; i++){
            printf("%d\n",v[i]);
        }
        v.clear();
    }
    printf("0 0\n");
    return 0;
}
