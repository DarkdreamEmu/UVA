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

int num=0,i=0;

struct person{
    string department,title,first,last,street,home,work,mailbox;
};

person office[10000];

bool cmp(person A,person B){
    return (A.last<B.last);
}

void ans_me(){
    sort(office,office+num,cmp);
    for(int i=0; i<num; i++){
        puts("----------------------------------------");
        cout<<office[i].title<<" "<<office[i].first<<" "<<office[i].last<<endl;
        cout<<office[i].street<<endl;
        cout<<"Department: "<<office[i].department<<endl;
        cout<<"Home Phone: "<<office[i].home<<endl;
        cout<<"Work Phone: "<<office[i].work<<endl;
        cout<<"Campus Box: "<<office[i].mailbox<<endl;
    }
}

int main(){
 //   freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    string str,s;
    getchar();
    while(t--){
        getline(cin,str);
        //getchar();
        while(getline(cin,s)){
            if(s.size()==0)break;
            office[i].department=str;
            int sz=s.size();
            int cnt=0;
            string substring;
            int index=0;
            for(int j=0; j<sz; j++){
                if(s[j]==','){
                    substring=s.substr(index,j-index);
                    index=j+1;
                    if(cnt==0)office[i].title=substring;
                    else if(cnt==1)office[i].first=substring;
                    else if(cnt==2)office[i].last=substring;
                    else if(cnt==3)office[i].street=substring;
                    else if(cnt==4)office[i].home=substring;
                    else if(cnt==5)office[i].work=substring;
                    cnt++;
                }
                else if(j==sz-1){
                    substring=s.substr(index,j-index+1);
                    office[i].mailbox=substring;
                }
            }
            i++;
            num++;
        }
    }
    ans_me();
    return 0;
}

