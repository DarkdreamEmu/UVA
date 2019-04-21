#include <bits/stdc++.h>
using namespace std;

string s[1000];
string t[1000];
int dp[1000][1000];

int lcw(int m,int n){

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
    return dp[0][0];
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cs=1;
    string a,b;
    while(getline(cin,a)){
        getline(cin,b);
        for(int i=0; i<a.size(); i++){
            if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<'Z'||a[i]>='0'&&a[i]<='9'){
                continue ;
            }
            else{
                a[i]=' ';
            }
        }
        for(int i=0; i<b.size(); i++){
            if(b[i]>='a'&&b[i]<='z'||b[i]>='A'&&b[i]<'Z'||b[i]>='0'&&b[i]<='9'){
                continue ;
            }
            else{
                b[i]=' ';
            }
        }

        stringstream ss(a);
        int ii=0;
        while(ss>>s[ii]){
            ii++;
        }
        stringstream mm(b);
        int jj=0;
        while(mm>>t[jj]){
            jj++;
        }

        int res=lcw(ii,jj);

        if(ii==0||jj==0){
            printf("%2d. Blank!\n",cs++);
        }
        else{
            printf("%2d. Length of longest match: %d\n",cs++,res);
        }
    }
    return 0;
}
