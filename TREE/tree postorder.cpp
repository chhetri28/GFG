#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node*root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void printporec(node*root){
    if(root==NULL){
        return;
    }
    printporec(root->left);
    printporec(root->right);
    cout<<root->data<<" ";
}
int main(){
    node*root=buildTree();
    printporec(root);
}