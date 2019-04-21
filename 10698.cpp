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

map< string,int >played;
map< string,int >point;
map< string,int >goals;
map< string,int >against;
map< string,int >win;

void process(){
    string team1,team2;
    char extra;
    int goal_1,goal_2;
    cin>>team1;
    cin>>goal_1;
    cin>>extra;
    cin>>goal_2;
    cin>>team2;
    if(goal_1>goal_2){
        win[team1]++;
        point[team1]+=3;
        point[team2]+=0;
    }
    else if(goal_1<goal_2){
        win[team2]++;
        point[team2]+=3;
        point[team1]+=0;
    }
    else{
        point[team1]+=1;
        point[team2]+=1;
    }
    played[team1]++;
    played[team2]++;
    goals[team1]+=goal_1;
    goals[team2]+=goal_2;
    against[team1]+=goal_2;
    against[team2]+=goal_1;
}

struct single{
    string name,upper;
    int pnt,play,scored,suffered,diffrence;
    single(){
        name="";
        pnt=play=scored=suffered=diffrence=0;
    }
};

bool cmp(single A, single B){
    if(A.pnt!=B.pnt)return A.pnt>B.pnt;
    else if(A.pnt==B.pnt){
        if(A.diffrence!=B.diffrence)return A.diffrence>B.diffrence;
        else if(A.diffrence==B.diffrence){
            if(A.scored!=B.scored)return A.scored>B.scored;
            else{
                for(int i=0; ; i++){
                    char a = A.name[i];
                    char b = B.name[i];
                    if(a!=b){
                        a=tolower(a);
                        b=tolower(b);
                        return a<b;
                    }
                }
            }
        }
    }
}

void ans_me(single take[10100],int num){
    int positon;
    for(int i=0; i<num; i++){
        if(i==0||take[i].pnt!=take[i-1].pnt||take[i].diffrence!=take[i-1].diffrence||take[i].scored!=take[i-1].scored){
            positon=i+1;
            printf("%2d.",positon);
        }
        else{
            printf("   ");
        }
        printf("%16s",take[i].name.c_str());
        printf("%4d%4d%4d%4d%4d",take[i].pnt,take[i].play,take[i].scored,take[i].suffered,take[i].diffrence);
        if(!take[i].play){
            cout<<setw(7)<<"N/A";
        }
        else{
            double percentage=(double)((take[i].pnt*100.00)/(3.00*take[i].play));
            printf("%7.2f",percentage);
        }
        printf("\n");
    }
    played.clear();
    point.clear();
    goals.clear();
    against.clear();
    win.clear();
}

int main(){
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    string s;
    int t,g;
    bool ok=false;
    while( scanf("%d %d",&t,&g) &&(t+g) ){
        if(ok)printf("\n");
        ok=true;
        vector <string> squads;
        squads.clear();
        for( int i=0; i<t; i++ ){
            cin>>s;
            squads.push_back(s);
        }
        for( int i=0; i<g; i++ ){
            process();
        }
        single take[10100];
        int j=0;
        for(int i=0; i<t; i++){
            string str=squads[i];
            take[j].name=str;
            take[j].play=played[str];
            take[j].pnt=point[str];
            take[j].scored=goals[str];
            take[j].suffered=against[str];
            take[j].diffrence=(goals[str]-against[str]);
            j++;
        }
        sort(take,take+j,cmp);
        ans_me(take,t);
    }
    return 0;
}
