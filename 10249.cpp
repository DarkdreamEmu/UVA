#include <bits/stdc++.h>
using namespace std;

struct team{
    int idd;
    int number;
};

struct table{
    int id;
    int capacity;
};

bool cmp1(team a1,team a2){
    return (a1.number>a2.number);
}

bool cmp2(table t1,table t2){
    return (t1.capacity>t2.capacity);
}

void solve(team all[],table troll[],int m,int n){

    sort(all,all+m,cmp1);
    sort(troll,troll+n,cmp2);

    vector<int>res[1010];
    bool ok=true;

    for(int i=0; i<m; i++){
        int tmp=all[i].number;
        for(int j=0; j<n; j++){
            if(!tmp){
                break;
            }
            if(troll[j].capacity){
                res[all[i].idd-1].push_back(troll[j].id);
                tmp--;
                troll[j].capacity--;
            }
            else{
                continue;
            }
        }
        if(tmp){
            ok=false;
            break;
        }
    }
    if(!ok){
        printf("0\n");
    }
    else{
        printf("1\n");
        for(int i=0; i<m; i++){
            sort(res[i].begin(),res[i].end());
            for(int j=0; j<res[i].size(); j++){
                printf("%d",res[i][j]);
                if(j<res[i].size()-1){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)&&(m+n)){
        team all[m+10];
        table troll[n+10];

        for(int i=0; i<m; i++){
            scanf("%d",&all[i].number);
            all[i].idd=i+1;
        }
        for(int i=0; i<n; i++){
            scanf("%d",&troll[i].capacity);
            troll[i].id=i+1;
        }
        solve(all,troll,m,n);
    }
    return 0;
}
