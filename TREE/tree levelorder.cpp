#include<bits/stdc++.h>
using namespace std;
class tree{
    public:
    int data;
    tree*left;
    tree*right;
    tree(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
tree*build(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    tree*root=new tree(data);
    root->left=build();
    root->right=build();
    return root;
}
int height(tree*root){
    if(root==NULL){
        return 0;
    }
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs);
}
void printknode(tree*node,int k){
    if(tree==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printknode(tree*node,k-1);
    printknode(tree*node,k-1);
    return;
}
void levelorder(tree*root){
    int H=height(root);
    for(int i=1;i<=H;i++){
        printknode(root,i);
    }
    return;
}
int main(){
    tree*root=build();
    print(root);
    return;
}