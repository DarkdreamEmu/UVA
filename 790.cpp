/**Bismillah-ir-Rahman-ir-Rahim**/

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n) for(LL i=0; i<n; i++)
#define RFOR(i,n) for(LL i=n-1; i>=0; i--)
#define FILL(A,value) memset(A,value,sizeof(A))
#define LL long long int
#define sI(a) scanf("%d",&a)
#define pI(a) printf("%d",a)
#define sI2(a,b) sI(a),sI(b)
#define pI2(a,b) pI(a) , pI(b)
#define sL(a) scanf("%lld",&a)
#define pL(a) printf("%lld",a)
#define sL2(a,b) sL(a),sL(b)
#define pL2(a,b) pL(a) , pL(b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define pN printf("\n")
#define pS printf(" ");
#define N 1000001
#define PI 3.14159

map< string,int >store;
vector<int>wrong[40];
vector<int>visited[40];
vector<int>sub_time[40];
int solved[40];
int duration[40];
map<int,int>submission;

struct contestant{
    int team,solving,dur;
};

bool cmp(contestant A,contestant B){
    if(A.solving!=B.solving)return A.solving>B.solving;
    else{
        if(A.dur!=B.dur)return A.dur<B.dur;
        else if(A.dur==B.dur)return A.team<B.team;
    }
}

bool check(int team,int problem){
    for(int i=0; i<visited[team].size(); i++){
        if(problem==visited[team][i]){
            return false;
        }
    }
    return true;
}

void ans_me(contestant take[40],int num){
    int ranking=1;
    int before=1;
    if(num)cout<<"RANK TEAM PRO/SOLVED TIME"<<endl;
    for(int i=0; i<num; i++){
        if(i==0){
            cout<<setw(4)<<ranking;
        }
        else if((take[i].solving==take[i-1].solving)&&(take[i].dur==take[i-1].dur)){
            cout<<setw(4)<<ranking;
            before++;
        }
        else{
            ranking+=before;
            cout<<setw(4)<<ranking;
            before=1;
        }
        cout<<setw(5)<<take[i].team;
        if(take[i].solving!=0){
            cout<<setw(5)<<take[i].solving;
            cout<<setw(11)<<take[i].dur;
        }
        printf("\n");
    }
}

int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int test;
    scanf("%d",&test);
    getchar();
    getchar();
    while(test--){
        int num=1,mx=0;
        memset(duration,0,sizeof(duration));
        memset(solved,0,sizeof(solved));
        for(int i=0; i<40; i++){
            visited[i].clear();
            wrong[i].clear();
            sub_time[i].clear();
        }
        char str[100];
        store.clear();
        submission.clear();
        vector<string>recal;
        recal.clear();
        while(gets(str)){
             if(strlen(str)==0)break;
             recal.push_back((string)str);
        }
        int sz=recal.size();
        sort(recal.begin(),recal.end());
        for(int i=0; i<sz; i++){
             string s=recal[i];
             int team,total_time;
             string problem,tm;
             char judge;
             stringstream ss(s);
             ss>>team;ss>>problem;ss>>tm;ss>>judge;
             string hr,mn;
             int ind=tm.find(":");
             hr=tm.substr(0,ind);
             mn=tm.substr(ind+1,s.size());
             stringstream hhh(hr);
             int hour;
             hhh>>hour;
             stringstream mmm(mn);
             int minutes;
             mmm>>minutes;
             total_time=(hour*60)+minutes;
             if(!store[problem]){
                store[problem]=num;
                num++;
             }
             if(judge=='N'){
                wrong[team].push_back(store[problem]);
                sub_time[team].push_back(total_time);
             }
             else if(judge=='Y'&&check(team,store[problem])){
                int sz=wrong[team].size();
                int cnt=0;
                for(int i=0; i<sz; i++){
                    if(store[problem]==wrong[team][i]){
                       cnt++;
                   }
                }
                solved[team]++;
                duration[team]+=(cnt*20)+total_time;
                visited[team].push_back(store[problem]);
             }
             submission[team]++;
             mx=max(team,mx);
        }
        int j=0;
        contestant take[40];
        for(int i=1; i<=mx; i++){
            take[j].solving=solved[i];
            take[j].dur=duration[i];
            take[j].team=i;
            j++;
        }
        sort(take,take+j,cmp);
        ans_me(take,j);
        if(test&&j)printf("\n");
    }
    return 0;
}
