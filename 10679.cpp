#include <bits/stdc++.h>
using namespace std;

void compute_lps(string pattern,int m,int lps[]){
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

void kmp(string str,string pattern){
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
            printf("y\n", i-j);
            ok=true;
            j=lps[j-1];
            break;
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
    if(!ok){
        printf("n\n");
    }
}

int main(){
    string str,pattern;
    int n;
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>str;
        scanf("%d",&n);
        while(n--){
            cin>>pattern;
            kmp(str,pattern);
        }
    }
    return 0;
}

