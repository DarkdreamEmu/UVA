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

int main(){
    int n;
    while( scanf("%d",&n)==1 ){
        int ar[n+10];
        FOR(i,n) scanf("%d",&ar[i]);
        sort(ar,ar+n);
        int cnt=0,number=0,times=0;
        if( n%2 ){
            number=ar[n/2];
            FOR(i,n){ if(ar[i]==number) cnt++; }
            times=1;
        }
        else{
            int left_indx=n/2-1;
            int right_indx=n/2;
            number=ar[left_indx];
            for( int i=0; i<=left_indx; i++){
                if( ar[i]==ar[left_indx] )cnt++;
            }
            for( int i=right_indx; i<n; i++ ){
                if(ar[i]==ar[right_indx]){
                    cnt++;
                }
            }
            times=ar[right_indx]-ar[left_indx]+1;
        }
        printf("%d %d %d\n",number,cnt,times);
    }
    return 0;
}
