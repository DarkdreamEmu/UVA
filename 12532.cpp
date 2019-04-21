#include <bits/stdc++.h>
using namespace std;

#define mx 200000

int arr[mx];
int tree[mx * 3];

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] * tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 1;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 * p2;
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] * tree[Right];
}

int main(){
    int n,q;
    while(scanf("%d%d",&n,&q)==2){
        for(int i=1; i<=n; i++){
            int tt;
            scanf("%d",&tt);
            if(tt>0){
                arr[i]= 1;
            }
            else if(tt==0){
                arr[i]= 0;
            }
            else{
                arr[i]= -1;
            }
        }
        init(1,1,n);
        while(q--){
            char ch;
            int a,b;
            scanf(" %c%d%d",&ch,&a,&b);
            if(ch=='C'){
                if(b>0){
                    b=1;
                }
                else if(b==0){
                    b=0;
                }
                else{
                    b=-1;
                }
                update(1,1,n,a,b);
            }
            else{
                int sum=query(1,1,n,a,b);
                if(sum==0){
                    printf("0");

                }
                else if(sum>0){
                    printf("+");
                }
                else{
                    printf("-");
                }
            }
        }
        printf("\n");
    }
    return 0;
}

