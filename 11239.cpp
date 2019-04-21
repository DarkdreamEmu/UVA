#include <bits/stdc++.h>
using namespace std;

map<string,int>a;
map<int,string>b;

map<string,int>c;
map<int,string>d;
map<string,int>freq;

int f[110][11000];

void clear(){
	a.clear();
	b.clear();
	c.clear();
	d.clear();
	freq.clear();
	memset(f,0,sizeof(f));
}

struct Structure{
	string cr;
	int num;
};

bool cmp(Structure a1,Structure a2){
	if(a1.num!=a2.num){
		return a1.num>a2.num;
	}
	else{
		return a1.cr<a2.cr;
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    string s;
    int x=1;
    while(getline(cin,s)&&s!="0"){
        clear();
        if(!a[s]){
            a[s]=x;
            b[x]=s;
        }
        x++;
        int y=1;
        string course=s;
        while(getline(cin,s)&&s!="1"){
            if(s[0]>='a'&&s[0]<='z'){
                if(!c[s]){
                    c[s]=y;
                    d[y]=s;
                    y++;
                }
                freq[s]++;
                int u=a[course];
                int v=c[s];
                f[u][v]++;
            }
            else{
                if(!a[s]){
                    a[s]=x;
                    b[x]=s;
                    x++;
                }
                course=s;
            }
        }

        Structure arr[x+10];
        int n=0;

        for(int i=1; i<x; i++){
            int cnt=0;
            for(int j=1; j<y; j++){
            	string sss=d[j];
                if(f[i][j]==freq[sss]&&freq[sss]){
                    cnt++;
                }
            }
            string str=b[i];
            arr[n].cr=str;
            arr[n].num=cnt;
            n++;
        }
        sort(arr,arr+n,cmp);
        for(int i=0; i<n; i++){
        	cout<<arr[i].cr<<" "<<arr[i].num<<endl;
		}
		x=1;
    }
    return 0;
}
