#include <bits/stdc++.h>
using namespace std;

#define N 252

/**set<int>st;

int LIS(int a[],int n){
    set<int>::iterator it;
    for (int i = 0; i < n; ++i)
	{
		st.insert(a[i]);
		it = st.find(a[i]);
		++it;
		if (it != st.end())
			st.erase(a[i]);
	}
	return st.size();
}**/

int ceilIndex(int input[], int T[], int end, int s){
    int start = 0;
    int middle;
    int len = end;
    while(start <= end){
        middle = (start + end)/2;
        if(middle < len && input[T[middle]] < s && s <= input[T[middle+1]]){
            return middle+1;
        }else if(input[T[middle]] < s){
            start = middle+1;
        }else{
            end = middle-1;
        }
    }
    return -1;
}

int LIS(int input[],int n){
    int T[n+10];
    int R[n+10];
    for(int i=0; i<n; i++){
        R[i]=-1;
    }
    T[0]=0;
    int len=0;
    for(int i=1; i<n; i++){
        if(input[T[0]]>input[i]){ //if input[i] is less than 0th value of T then replace it there.
            T[0]=i;
        }
        else if(input[T[len]]<input[i]){ //if input[i] is greater than last value of T then append it in T
            len++;
            T[len]=i;
            R[T[len]]=T[len-1];
        }
        else{ //do a binary search to find ceiling of input[i] and put it there.
             int index = ceilIndex(input, T, len,input[i]);
             T[index] = i;
            R[T[index]] = T[index-1];
        }
    }
    return len+1;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,p,q;
        scanf("%d %d %d",&n,&p,&q);
        int f[N*N];
        memset(f,0,sizeof(f));
        int cnt=0;
        int tak;
        int input[N*N];
        p++,q++;
        for(int i=1; i<=p; i++){
            scanf("%d",&tak);
            f[tak]=i;
        }
        for(int i=1; i<=q; i++){
            scanf("%d",&tak);
            if(f[tak]){
                input[cnt++]=f[tak];
            }
        }
        printf("Case %d: %d\n",cs++,LIS(input,cnt));
       //st.clear();
    }
    return 0;
}
