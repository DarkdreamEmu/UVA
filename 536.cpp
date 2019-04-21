#include "bits/stdc++.h"
using namespace std;

struct node{
    char data;
    node* left;
    node* right;
};


int SRC(string inorder,int start,int en,char data){
    for(int i=start; i<=en; i++){
        if(inorder[i]==data)return i;
    }
}

static int pindex=0;

node* construct_tree(string inorder,string preorder,int start,int en){
    if(start>en)return NULL;
    node* root=new node();
    root->data=preorder[pindex];
    pindex++;
    if(start==en)return root;
    int index=SRC(inorder,start,en,root->data);
    root->left=construct_tree(inorder,preorder,start,index-1);
    root->right=construct_tree(inorder,preorder,index+1,en);
    return root;
}

void postorder(node* root){
    if(root==NULL)return ;
    postorder(root->left);
    postorder(root->right);
    if(root->data>='A'&&root->data<='Z')cout<<root->data;
}
void deleteTree(node* root){
    if(root==NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(){
    string A,B;
    while(cin>>A>>B){
        node* root;
        pindex=0;
        root=construct_tree(B,A,0,A.size());
        postorder(root);
        printf("\n");
        deleteTree(root);
    }
    return 0;
}
