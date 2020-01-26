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
void printpre(tree *root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main(){
    tree*root=build();
    print(root);
    return;
}