#include <bits/stdc++.h>
using namespace std;

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

void LIS(int input[],int n){
	vector<int>res;
    int T[n];
    int R[n];
    for(int i=0; i<n; i++){
        R[i]=-1;
    }
    T[0]=0;
    int len=0;
    for(int i=1; i<n; i++){
        if(input[T[0]]>input[i]){
            T[0]=i;
        }
        else if(input[T[len]]<input[i]){
            len++;
            T[len]=i;
            R[T[len]]=T[len-1];
        }
        else{
            int index=ceilIndex(input,T,len,input[i]);
            T[index]=i;
            R[T[index]] = T[index-1];
        }
    }
    int index=T[len];
    printf("Max hits: %d\n",len+1);
    while(index!=-1){
        res.push_back(input[index]);
        index=R[index];
    }
    int sz=res.size();
    for(int i=sz-1; i>=0; i--){
    	printf("%d\n",res[i]);
	}
}

int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
    	int a[100000];
    	string s;
    	int i=0;
    	while(getline(cin,s)&&s.size()){
    		stringstream ss(s);
    		int m;
    		ss>>m;
    		a[i]=m;
    		i++;
		}
		LIS(a,i);
		if(t){
			printf("\n");
		}
	}
    return 0;
}


