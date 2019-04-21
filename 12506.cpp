#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        string take[1110];
        for(int i=0; i<n; i++){
            cin>>take[i];
        }
        sort(take,take+n);
        int cnt=0,pos=0;
        while(take[0][pos]==take[1][pos]){
            pos++;
        }
        cnt+=(pos+1);
        pos=0;
        while(take[n-1][pos]==take[n-2][pos]){
            pos++;
        }
        cnt+=(pos+1);
        for(int i=1; i<n-1; i++){
            int pos1=0,pos2=0;
            while(take[i][pos1]==take[i+1][pos1]){
                pos1++;
            }
            while(take[i][pos2]==take[i-1][pos2]){
                pos2++;
            }
            pos2=max(pos2,pos1);
            cnt+=(pos2+1);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
