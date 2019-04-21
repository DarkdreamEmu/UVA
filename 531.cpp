#include <bits/stdc++.h>
using namespace std;

vector<string>s,t;
int dp[1000][1000];

void lcs(){
    int m=s.size();
    int n=t.size();
    for(int i=m; i>=0; i--){
        for(int j=n; j>=0; j--){
            if(i==m||j==n){
                dp[i][j]=0;
            }
            else if(s[i]==t[j]){
                dp[i][j]=dp[i+1][j+1]+1;
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }

    int mx=-1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            mx=max(mx,dp[i][j]);
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(s[i]==t[j]&&dp[i][j]==mx){
                mx--;
                cout<<s[i];
                if(mx==0){
                    cout<<endl;
                }
                else{
                    cout<<" ";
                }
                break;
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string a;
    while(cin>>a){
        s.push_back(a);
        while(cin>>a&&a[0]!='#'){
            s.push_back(a);
        }
        string b;
        while(cin>>b&&b[0]!='#'){
            t.push_back(b);
        }
        lcs();
        s.clear();
        t.clear();
    }
    return 0;
}
