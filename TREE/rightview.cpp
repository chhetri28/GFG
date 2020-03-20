#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d):data(d),left(NULL),right(NULL){}
};
node* build(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node*root=new node(d);
    root->left=build();
    root->right=build();
    return root;
}
void helper(node*root,int level,int max_level){
    if(!root)return;
    if(level>max_level){
        cout<<root->data<<" ";
        max_level=level;
    }
    helper(root->right,level+1,max_level);
    helper(root->left,level+1,max_level);
}
void rightside(node*root){
    int max_level=0;
    helper(root,1,max_level);
}
int main(){
    node*root=build();
    rightside(root);
}