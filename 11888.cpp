#include <bits/stdc++.h>
using namespace std;
/*void compute_lps(string pattern,int m,int lps[]){
    int len=0;
    lps[0]=0;

    int i=1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

int kmp(string str,string pattern){
    int cnt=0;
    int n=str.size();
    int m=pattern.size();

    bool ok=false;

    int lps[m];
    compute_lps(pattern,m,lps);

    int i=0,j=0;
    while(i<n){
        if(pattern[j]==str[i]){
            i++;
            j++;
        }
        if(j==m){
            cnt++;
            ok=true;
            j=lps[j-1];
        }
        else if(i<n&&pattern[j]!=str[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return cnt;
}*/

string s;

bool ispalin(int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool alin(string s){
    int sz=s.size();
    for(int i=0; i<sz-1; i++){
        int a=ispalin(0,i);
        int b=ispalin(i+1,sz-1);
        if(a&&b){
            return true;
        }
    }
    return false;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>s;
        int sz=s.size();
        if(alin(s)){
            puts("alindrome");
        }
        else if(ispalin(0,sz-1)){
            puts("palindrome");
        }
        else{
            puts("simple");
        }
    }
    return 0;
}
