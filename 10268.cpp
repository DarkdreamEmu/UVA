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
    int x;
    string s;
    while(scanf("%d",&x)==1){
        getchar();
        getline(cin,s);
        int number;
        vector<int>store;
        stringstream ss(s);
        while(ss>>number){
            store.push_back(number);
        }
        int ans=0;
        int sz=store.size()-2;
        int exponent=1;
        for(int i=sz; i>=0; i--){
            ans=ans+((store[i]*(sz+1-i))*exponent);
           // cout<<ans<<endl;
            exponent*=x;
        }
        printf("%d\n",ans);
        store.clear();
    }
    return 0;
}

