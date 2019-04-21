#include <bits/stdc++.h>
using namespace std;

map<string,string>my;
map<string,int>f;
set<string>pl;
set<string>mi;
set<string>ch;

void pri(){
    if(mi.size()||ch.size()||pl.size()){
        set<string>::iterator a=pl.begin();
        int sz1=pl.size();
        int cn1=0;
        if(sz1){
            printf("+");
        }
        while(a!=pl.end()){
            cout<<*a;
            a++;
            if(cn1<sz1-1){
                printf(",");
            }
            cn1++;
        }
        if(sz1){
            printf("\n");
        }

        set<string>::iterator b=mi.begin();
        int sz2=mi.size();
        int cn2=0;
        if(sz2){
            printf("-");
        }
        while(b!=mi.end()){
            cout<<*b;
            b++;
            if(cn2<sz2-1){
                printf(",");
            }
            cn2++;
        }

        if(sz2){
            printf("\n");
        }

        set<string>::iterator c=ch.begin();
        int sz3=ch.size();
        int cn3=0;
        if(sz3){
            printf("*");
        }
        while(c!=ch.end()){
            cout<<*c;
            c++;
            if(cn3<sz3-1){
                printf(",");
            }
            cn3++;
        }
        if(sz3){
            printf("\n");
        }
    }
    else{
        printf("No changes\n");
    }
}

void format_map(string s){
	my.clear();
	f.clear();
	pl.clear();
	mi.clear();
	ch.clear();
    int sz=s.size();
    s[0]=' ';
    s.erase(sz-1);
    std::replace( s.begin(), s.end(), ',', ' ');
    std::replace( s.begin(), s.end(), ':', ' ');
    stringstream ss(s);
    int cnt=0;
    string pre;
    string str;
    while(ss>>str){
    	if(cnt%2==0){
    		pre=str;
		}
		else{
			my[pre]=str;
		}
		cnt++;
	}
}

void checking(string s){
    int sz=s.size();
    s[0]=' ';
    s.erase(sz-1);
    std::replace( s.begin(), s.end(), ',', ' ');
    std::replace( s.begin(), s.end(), ':', ' ');
    stringstream ss(s);
    int cnt=0;
    string pre;
    string str;
    while(ss>>str){
    	if(cnt%2==0){
    		if(my.find(str)==my.end()){
                pl.insert(str);
    		}
    		pre=str;
		}
		else{
            if(my.find(pre)!=my.end()){
                string po=my[pre];
			    if(po!=str){
                   ch.insert(pre);
			    }
			    f[pre]=1;
            }
		}
		cnt++;
	}

	map<string,string>::iterator it=my.begin();
	while(it!=my.end()){
        string tt=it->first;
        if(f.find(tt)==f.end()){
            mi.insert(tt);
        }
        it++;
	}
	pri();
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string a;
        string b;
        cin>>a;
        cin>>b;
        format_map(a);
        checking(b);
        printf("\n");
    }
    return 0;
}
