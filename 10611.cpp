#include <bits/stdc++.h>
using namespace std;

int binary(int a[],int n,int k){
    int lo=0,hi=n-1,mid;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(a[mid]==k){
            return mid+1;
        }
        else if(a[mid]>k){
            hi=mid-1;
        }
        else if(a[mid]<k){
            lo=mid+1;
        }
    }
    return -1;
}

int main(){
    int n;
    while(scanf("%d",&n)==1){
        int a[n+10];
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        vector<int>v(a,a+n);
        int q;
        scanf("%d",&q);
        while(q--){
            int h;
            scanf("%d",&h);
            //int res=binary(a,n,h);
            vector<int>::iterator low,up;
            low=lower_bound(v.begin(),v.end(),h);
            up=upper_bound(v.begin(),v.end(),h);
            int ll=(low-v.begin());
            int pp=(up-v.begin());
            //cout<<ll<<" "<<pp<<endl;
            if(ll==0){
                printf("X");
            }
            else{
                printf("%d",a[ll-1]);
            }
            if(pp==0||pp==n){
                printf(" X\n");
            }
            else{
                printf(" %d\n",a[pp]);
            }
        }
    }
    return 0;
}
