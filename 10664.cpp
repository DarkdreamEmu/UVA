#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    scanf("%d",&t);
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        stringstream ss(s);
        int n=0,all=0;
        int ar[110];
        while(ss>>ar[n]){
            all+=ar[n];
            n++;
        }
        if(all%2){
            printf("NO\n");
            continue;
        }
        all=all/2;
        int dp[all+10];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0; i<n; i++){
            for(int j=all; j>=0; j--){
                if(dp[j]&&(j+ar[i])<=all){
                    dp[j+ar[i]]=1;
                }
            }
        }
        if(dp[all]){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
