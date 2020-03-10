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

node* buildtree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node*root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}
int solve(node* root,bool &check){
    if(!root){
        return 0;
    }
    int l=solve(root->left,check);
    int r=solve(root->left,check);
    if(abs(l-r)>1){
        check=false;
    }
    return max(l,r)+1;
}


bool isbalance(node* root){
    bool check=true;
    solve(root,check);
    return check;
}
int main(){
    node*root=buildtree();  
    cout<<isbalance(root);
}