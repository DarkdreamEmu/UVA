#include <bits/stdc++.h>
using namespace std;

map<int,vector<int> >my;
vector<int>temp;

int mat[4][11100];
int fre[11100];
int res[6];

void reset(){
    memset(mat,0,sizeof(mat));
    memset(res,0,sizeof(res));
    memset(fre,0,sizeof(fre));
    my.clear();
    temp.clear();
}

int main(){
//	freopen("in.txt","r",stdin);
 	//freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--){
        reset();
        int mn=1000000,mx=0;
        for(int i=1; i<=3; i++){
            int n;
            scanf("%d",&n);
            for(int j=0; j<n; j++){
                int a;
                scanf("%d",&a);
                mat[i][a]++;
                fre[a]++;
                mn=min(a,mn);
                mx=max(a,mx);
            }
        }
        printf("Case #%d:\n",cas++);
        int mxxx=0;
        for(int i=1; i<=3; i++){
            int cnt=0;
            for(int j=mn; j<=mx; j++){
                if(fre[j]==mat[i][j]&&fre[j]!=0){
                    cnt++;
                    my[i].push_back(j);
                }
            }
            res[i]=cnt;
            mxxx=max(res[i],mxxx);
        }
        for(int j=1; j<=3; j++){
            if(my[j].size()==mxxx){
                printf("%d %d",j,mxxx);
                sort(my[j].begin(),my[j].end());
                for(int k=0; k<my[j].size(); k++){
                    if(k<my[j].size()){
                        cout<<" ";
                    }
                    cout<<my[j][k];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
