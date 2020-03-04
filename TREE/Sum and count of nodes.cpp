#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
node*buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
}
int count(node*root){
    if(!root){
        return 0;
    }
    return count(root->left)+count(root->right)+1;
}
int sum(node*root)
{
    if(!root){
        return 0;
    }
    return sum(root->left)+sum(root->right)+root->data;
}
int main(){
    node*root=buildTree();
    cout<<count(root)<<" "<<sum(root);
}