/** I am Back **/
#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional> // for less
// #include <iostream>
// using namespace __gnu_pbds;
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
 
#define MX 200001
 
#define PI 3.14159
#define pb push_back
#define MOD 1000000007
inline int gcd(int a, int b){return (b == 0 ? a : gcd(b, a % b));}
inline int lcm(int a, int b){return (a * (b / gcd(a, b))); }
inline LL bigmod(LL a,LL b,LL m){if(b==0)return 1%m;LL x=bigmod(a,b/2,m);x=(x*x)%m;if(b%2==1){x=(x*a)%m;}return x;}
inline LL phi(LL n) {LL ret=n;for(LL i=2; i*i<=n; i++){if(n%i==0){while(n%i==0)n/=i;}ret-=ret/i;}if(n>1){ret-=ret/n;}return ret;}
LL missing_number(LL A[],LL n){LL x1=A[0],x2=1;for(int i=1; i<n; i++)x1^=A[i];for(int i=2; i<=n+1; i++)x2^=i;return (x1^x2);}
bool isFibo(LL n){LL A=(5*n*n+4);LL B=(5*n*n-4); LL C=sqrt(A); LL D=sqrt(B); return (A==(C*C)||B==(D*D));}
LL classini(LL n){return (n&1)? -1: 1;} // f(n-1)*f(n+1) - f(n)*f(n)
LL factorial(int n){return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;}
LL catanal(LL n) {return (factorial(2*n)/((factorial(n+1)*factorial(n))));}//Dyck path// //1,1,2,5,14,42,132,429,1430,4862,16796,58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, 6564120420, 24466267020, 91482563640, 343059613650, 1289904147324, 4861946401452
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
 
string make_string(LL num){stringstream ss;ss<<num;string s;ss>>s;return s;}
LL make_num(string s){stringstream ss;LL tmp;ss<<s;ss>>tmp;return tmp;}
 
int SET(int mask,int pos){return (mask|(1<<pos));}
int check(int mask,int pos){return (mask&(1<<pos));}
 
// typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds_less;
// typedef tree<int, null_type, greater<int>, rb_tree_tag,tree_order_statistics_node_update> pbds_greater;
 

LL dp[(1<<15)+10][4][4];
LL mat[16][16];
int n; 
 
LL go(int mask , int pos , int one , int two){
	if(pos == n){
		return (one || two);
	}
	if(dp[mask][one][two]!=-1)return dp[mask][one][two];
	LL ans = 0;
	for(int i=0; i<n; i++){
		if(!(mask&(1<<i))){
			ans += go(mask|(1<<i) , pos+1, one&(mat[pos][i]==1),two|(mat[pos][i]==2));
		}
	}
	return dp[mask][one][two]=ans;
} 
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,cs=1;
    cin>>t;
    while(t--){
    	cin>>n;
    	FOR(i,n)FOR(j,n)cin>>mat[i][j];
    	FILL(dp,-1);
    	cout<<"Case "<<cs++<<": "<<go(0,0,1,0) <<endl;
    }
    return 0;
}