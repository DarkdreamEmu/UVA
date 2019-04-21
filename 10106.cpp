#include <bits/stdc++.h>
using namespace std;

#define itc(n) char(n+48)
#define cti(ch) (ch-48)
#define lld long long

string itos(lld n)
{
    ostringstream convert;
    convert<<n;
    return convert.str();
}


string add(string s1, string s2)
{
    int len1=s1.length(), len2=s2.length();
    if(len1<len2)                                   //s1 should be of greater length than s2
        return add(s2, s1);
    string ans="";
    int carry=0, i, s;
    for(i=1; i<=len1; i++)
    {
        s = carry+cti(s1[len1-i]);

        if(i<=len2)
            s += cti(s2[len2-i]);

        ans = itc(s%10)+ans;                        //finding the character to be added to the ans
        carry = s/10;                               //finding the carry
    }
    if(carry!=0)
        ans = itc(carry)+ans;

    return ans;
}

string multiply(string s1, string s2)
{
    int len1=s1.length(), len2=s2.length();
    if(len1<len2)
        return multiply(s2,s1);
    int i,j,p, carry=0;
    string result, net="", c;
    for(i=len2-1; i>=0; i--)
    {
        carry=0;
        result="";
        c="";
        for(j=len1-1; j>=0; j--)
        {
            p=cti(s1[j])*cti(s2[i]);
            result = itc((p+carry)%10)+result;
            carry=(p+carry)/10;
        }
        if(carry!=0)
        {
            c=itos(carry);
            result=c+result;

        }
        for(j=i; j<len2-1; j++)
            result+="0";

        net=add(net,result);
    }
    return net;
}

int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    string a,b;
    while(cin>>a>>b){
        if(a=="0"||b=="0"){
            cout<<"0"<<endl;
        }
        else{
            cout<<multiply(a,b)<<endl;
        }
    }
    return 0;
}
