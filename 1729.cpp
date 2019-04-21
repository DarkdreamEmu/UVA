#include <bits/stdc++.h>
using namespace std;

string day_str[7] = {
	"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"
};
string mon_str[12] = {
	"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL",
	"AUG", "SEP", "OCT", "NOV", "DEC"
};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        string mon,day;
        cin>>mon>>day;
        int d=0;
        for(int i=0; i<12; i++){
            if(mon==mon_str[i]){
                d=i;
                break;
            }
        }
        d=days[d];
        int st=0;
        for(int i=0; i<7; i++){
            if(day==day_str[i]){
                st=i;
                break;
            }
        }
        int cnt=0;
        for(int i=0; i<d; i++){
            if((st+i)%7==5||(st+i)%7==6){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
