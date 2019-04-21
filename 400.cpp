#include <bits/stdc++.h>
using namespace std;

string stor[110];
int len[110];

int main(){
    int n;
    while(cin>>n){
        int mx=0;
        for(int i=0; i<n; i++){
            cin>>stor[i];

        }
        sort(stor,stor+n);
        for(int i=0; i<n; i++){
            len[i]=stor[i].size();
            mx=max(mx,len[i]);
        }
        int c=62/(mx+2);
        int r=n/c+(n%c>0);
        for(int i=0; i<60; i++){
            printf("-");
        }
        printf("\n");
        for(int i=0; i<r; i++){
            for(int j=i; j<n;){
                int l=mx-len[j];
                cout<<stor[j];
                while(l--){
                    printf(" ");
                }
                j+=r;
                if(j<n){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
