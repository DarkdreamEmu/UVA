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

int main(){
    char s[50];
    while(gets(s)){
        int sz=strlen(s);
        vector<string>store;
        for(int i=0; i<10; i++){
            prev_permutation(s,s+sz);
        }
        store.push_back(s);
        for(int i=0; i<21; i++){
            next_permutation(s,s+sz);
            string temp=(string)s;
            store.push_back(temp);
        }
        int mn=-1;
        string res;
        for(int i=0; i<store.size(); i++){
            string ss=store[i];
            int sum=1000000;
            for(int j=0; j<sz-1; j++){
                sum=min(sum,abs(ss[j]-ss[j+1]));
            }
            if(sum>mn){
                mn=sum;
                res=(string)ss;
            }
        }
        cout<<res<<mn<<endl;
    }
    return 0;
}
