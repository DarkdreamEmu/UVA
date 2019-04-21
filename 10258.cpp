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

vector<int>wrong[110];
vector<int>visited[110];
int solved[110];
int duration[110];
map<int,int>submission;

struct contestant{
    int team,solving,dur;
};

bool cmp(contestant A,contestant B){
    if(A.solving!=B.solving)return A.solving>B.solving;
    else{
        if(A.dur!=B.dur)return A.dur<B.dur;
        else if(A.dur==B.dur)return A.team<B.team;
        else return false;
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

int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int t;
    string s;
    scanf("%d\n",&t);
    while(t--){
        memset(solved,0,sizeof(solved));
        memset(duration,0,sizeof(duration));
        for(int i=0; i<110; i++){
            wrong[i].clear();
            visited[i].clear();
        }
        submission.clear();
        int mx=0;
        while(getline(cin,s)&&s.size()){
            int team,problem,tm;
            char judge;
            stringstream ss(s);
            ss>>team;ss>>problem;ss>>tm;ss>>judge;
            if(judge=='I'){
                wrong[team].push_back(problem);
            }
            else if(judge=='C'&&check(team,problem)){
                int sz=wrong[team].size();
                int cnt=0;
                for(int i=0; i<sz; i++){
                    if(problem==wrong[team][i]){
                        cnt++;
                    }
                }
                solved[team]++;
                duration[team]+=(cnt*20)+tm;
                visited[team].push_back(problem);
            }
            submission[team]++;
            mx=max(team,mx);
        }
        int j=0;
        contestant take[110];
        for(int i=1; i<=mx; i++){
            if(submission[i]){
                take[j].team=i;
                take[j].solving=solved[i];
                take[j].dur=duration[i];
                j++;
            }
        }
        sort(take,take+j,cmp);
        for(int i=0; i<j; i++){
            cout<<take[i].team<<" "<<take[i].solving<<" "<<take[i].dur<<endl;
        }
        if(t)printf("\n");
    }
    return 0;
}
