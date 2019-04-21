#include <stdio.h>
#include <cstring>

int mx=0;
struct node{
    int cnt;
    node* next[2];
    node(){
        cnt=0;
        for(int i=0; i<2; i++){
            next[i]=NULL;
        }
    }
};

void _insert(node* root,char* str,int len){
    node* curr=root;
    for(int i=0; i<len; i++){
        int id=str[i]-'0';
        ++(curr->cnt);
        if(curr->next[id]==NULL){
            curr->next[id]=new node();
        }
        curr=curr->next[id];
    }
    ++(curr->cnt);
}

void ans_me(node* curr,int len){
    for(int i=0; i<2; i++){
        if(curr->next[i]){
            ans_me(curr->next[i],len+1);
        }
    }
    curr->cnt*len>mx ? mx=curr->cnt*len:mx;
}

void del(node* curr){
    for(int i=0; i<2; i++){
        if(curr->next[i]){
            del(curr->next[i]);
        }
    }
    delete(curr);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        node* root=new node();
        int n;
        scanf("%d",&n);
        while(n--){
            char str[1100];
            scanf("%s",str);
            _insert(root,str,strlen(str));
        }
        mx=0;
        ans_me(root,0);
        printf("%d\n",mx);
        del(root);
    }
    return 0;
}
