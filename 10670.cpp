#include <bits/stdc++.h>
using namespace std;

struct agency{
    string name;
    int one,half,total;
};

bool cmp(agency a,agency b){
    if(a.total==b.total){
        return a.name<b.name;
    }
    return a.total<b.total;
}

int main(){
    int t,cs=1;
    scanf("%d",&t);
    while(t--){
        int n,m,q;
        scanf("%d %d %d",&n,&m,&q);
        agency take[110];
        for(int i=0; i<q; i++){
            string s,tem,first,second;
            cin>>s;
            int ind=s.find(':');
            tem=s.substr(0,ind);
            int coma=s.find(',');
            first=s.substr(ind+1,coma);
            second=s.substr(coma+1,s.size());
            int num1,num2;
            stringstream ss(first);
            ss>>num1;
            stringstream sss(second);
            sss>>num2;
            take[i].name=tem;
            take[i].one=num1;
            take[i].half=num2;
        }
        for(int i=0; i<q; i++){
            int cost=0;
            int total=n;
            while(total!=m){
                if(total/2<m){
                    cost+=((total-m)*take[i].one);
                    total=m;
                }
                else{
                    int temp=total-total/2;
                    if(temp*take[i].one>take[i].half){
                        cost+=(take[i].half);
                    }
                    else{
                        cost+=(temp*take[i].one);
                    }
                    total/=2;
                }
            }
            take[i].total=cost;
        }
        sort(take,take+q,cmp);
        printf("Case %d\n",cs++);
        for(int i=0; i<q; i++){
            cout<<take[i].name<<" "<<take[i].total<<endl;
        }
    }
    return 0;
}
