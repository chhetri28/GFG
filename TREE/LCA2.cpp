#include<iostream>
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
node* LCA(node* root,int n1,int n2){
    // base case
    if(root==NULL){
        return NULL;
    }
    // if n1 or n2 is root
    if(root->data==n1 or root->data==n2){
        return root;
    }
    //look for left subtree and right subtree
    node* left_lca=LCA(root->left,n1,n2);
    node* right_lca=LCA(root->right,n1,n2);
    // if one key is present in one subtree and visa versa
    if(left_lca and right_lca) return root;
    // check for right or left subtree for LCA
    return (left_lca!=NULL)?left_lca:right_lca;
}
int main(){
    node* root=buildTree();
    LCA(root,4,5);
}