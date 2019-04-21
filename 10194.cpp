#include <bits/stdc++.h>
using namespace std;

map<int,string>my;

map<string,int>point;
map<string,int>played;
map<string,int>win;
map<string,int>ties;
map<string,int>losses;
map<string,int>scored;
map<string,int>against;


struct calculate{
    string name;
    int pnt;
    int game_played;
    int wn;
    int td;
    int loss;
    int goal_dif;
    int sr;
    int ag;
};

void check(string s){
    int sz=s.size();
    vector<int>v;
    int at_ra;
    for(int i=0; i<sz; i++){
        if(s[i]=='#'){
            v.push_back(i);
            s[i]=' ';
        }
        if(s[i]=='@'){
            at_ra=i;
            s[i]=' ';
        }
    }
    string tm1,tm2,score;
    tm1=s.substr(0,v[0]);
    tm2=s.substr(v[1]+1,s.size()-1);
    score=s.substr(v[0],v[1]);
    stringstream ss(score);
    int gl1,gl2;
    ss>>gl1;
    ss>>gl2;
    if(gl1==gl2){
        point[tm1]+=1;
        point[tm2]+=1;
        ties[tm1]+=1;
        ties[tm2]+=1;
    }
    else if(gl1>gl2){
        point[tm1]+=3;
        win[tm1]++;
        losses[tm2]++;
    }
    else{
        point[tm2]+=3;
        win[tm2]++;
        losses[tm1]++;
    }
    played[tm1]++;
    played[tm2]++;
    scored[tm1]+=gl1;
    scored[tm2]+=gl2;
    against[tm1]+=gl2;
    against[tm2]+=gl1;
    //cout<<tm1<<" "<<gl1<<" "<<tm2<<" "<<gl2<<endl;
    v.clear();
}

void clean(){
    my.clear();
    point.clear();
    played.clear();
    win.clear();
    ties.clear();
    losses.clear();
    scored.clear();
    against.clear();
}

bool cmp(calculate team1,calculate team2){
    if(team1.pnt!=team2.pnt){
        return team1.pnt>team2.pnt;
    }
    else{
        if(team1.wn!=team2.wn){
            return team1.wn>team2.wn;
        }
        else{
            if(team1.goal_dif!=team2.goal_dif){
                return team1.goal_dif>team2.goal_dif;
            }
            else{
                if(team1.sr!=team2.sr){
                    return team1.sr>team2.sr;
                }
                else{
                    if(team1.game_played!=team2.game_played){
                        return team1.game_played<team2.game_played;
                    }
                    else{
                        for(int i=0; ; i++){
                            char a = team1.name[i];
                            char b = team2.name[i];
                            if (a >= 'A'&&a <= 'Z')	a += 32;
                            if (b >= 'A'&&b <= 'Z')	b += 32;
                            if (a == '\0')	return true;
                            if (b == '\0')	return false;
                            if (a > b)	return false;
                            if (a < b)	return true;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    cin.ignore();
    while(t--){
        clean();
        string tournament;
        getline(cin,tournament);
        int n;
        scanf("%d",&n);
        cin.ignore();
        for(int i=1; i<=n; i++){
            string team;
            getline(cin,team);
            my[i]=team;
        }
        int m;
        scanf("%d",&m);
        cin.ignore();
        for(int i=0; i<m; i++){
            string str;
            getline(cin,str);
            check(str);
        }
        int ind=0;
        calculate take[n+10];
        for(int i=1; i<=n; i++){
            string input=my[i];
            take[ind].name=input;
            take[ind].pnt=point[input];
            take[ind].game_played=played[input];
            take[ind].wn=win[input];
            take[ind].td=ties[input];
            take[ind].loss=losses[input];
            take[ind].goal_dif=(scored[input]-against[input]);
            take[ind].sr=scored[input];
            take[ind].ag=against[input];
            ind++;
        }
        cout<<tournament<<endl;
        sort(take,take+ind,cmp);
        for(int i=0; i<n; i++){
            cout<<i+1<<")"<<" "<<take[i].name<<" "<<take[i].pnt<<"p,"<<" "<<take[i].game_played<<"g ("<<take[i].wn<<
            "-"<<take[i].td<<"-"<<take[i].loss<<"), "<<take[i].goal_dif<<"gd ("<<take[i].sr<<"-"<<take[i].ag<<")"<<endl;
        }
        if(t){
            printf("\n");
        }
    }
    return 0;
}
