#include <bits/stdc++.h>
using namespace std;

string I="I=";
string V="U=";
string P="P=";

double check(char ch){
    if(ch=='m')return (0.001);
    if(ch=='k')return 1000;
    if(ch=='M')return 1000000;
    return 1;
}

int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        double result;
        int current=s.find(I);
        int voltage=s.find(V);
        int power=s.find(P);
        printf("Problem #%d\n",cs++);
        if(current!=-1&&voltage!=-1&&power==-1){
            string a="",b="",aa,bb;
            double first,second;
            for(int i=current+2; s[i]!='A'&&i<s.size(); i++){
                a+=s[i];
            }
            for(int i=voltage+2; s[i]!='V'&&i<s.size(); i++){
                b+=s[i];
            }
            int sza=a.size();
            int szb=b.size();
            if(a[a.size()-1]=='M'){
                sza--;
            }
            if(b[b.size()-1]=='k'){
                szb--;
            }
            aa=a.substr(0,sza);
            bb=b.substr(0,szb);
            stringstream ss(aa);
            ss>>first;
            stringstream sss(bb);
            sss>>second;
            result=first*second;
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            result*=(check(a[0])*check(b[0]));
           // cout<<a<<" "<<b<<endl;
           // cout<<first<<" "<<second<<endl;
           // cout<<b[0]<<" "<<a[0]<<endl;
            printf("P=%.2fW\n",result);
        }
        else if(current==-1&&voltage!=-1&&power!=-1){
            string a="",b="",aa,bb;
            float first,second;
            for(int i=power+2; s[i]!='W'&&i<s.size(); i++){
                a+=s[i];
            }
            for(int i=voltage+2; s[i]!='V'&&i<s.size(); i++){
                b+=s[i];
            }
            int sza=a.size();
            int szb=b.size();
            if(a[a.size()-1]=='m'){
                sza--;
            }
            if(b[b.size()-1]=='k'){
                szb--;
            }
            aa=a.substr(0,sza);
            bb=b.substr(0,szb);
            stringstream ss(aa);
            ss>>first;
            stringstream sss(bb);
            sss>>second;
            result=first/second;
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            result*=(check(a[0])*check(b[0]));
           // cout<<a<<" "<<b<<endl;
           // cout<<first<<" "<<second<<endl;
           // cout<<b[0]<<" "<<a[0]<<endl;
            printf("I=%.2fA\n",result);
        }
        else{
            string a="",b="",aa,bb;
            float first,second;
            for(int i=power+2; s[i]!='W'&&i<s.size(); i++){
                a+=s[i];
            }
            for(int i=current+2; s[i]!='A'&&i<s.size(); i++){
                b+=s[i];
            }
            int sza=a.size();
            int szb=b.size();
            if(a[a.size()-1]=='m'){
                sza--;
            }
            if(b[b.size()-1]=='M'){
                szb--;
            }
            aa=a.substr(0,sza);
            bb=b.substr(0,szb);
            stringstream ss(aa);
            ss>>first;
            stringstream sss(bb);
            sss>>second;
            result=first/second;
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            result*=(check(a[0])*check(b[0]));
           // cout<<a<<" "<<b<<endl;
           // cout<<first<<" "<<second<<endl;
            //cout<<b[0]<<" "<<a[0]<<endl;
            printf("U=%.2fV\n",result);
        }
        printf("\n");
    }
    return 0;
}
