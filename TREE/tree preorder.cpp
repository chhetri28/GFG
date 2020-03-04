#include<iostream>
#include<stack>
#include<algorithm>
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
void printprerec(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printprerec(root->left);
    printprerec(root->right);
}
void preorder(node*root){
    stack<node*>s;
    s.push(root);
    while (!s.empty())
    {
        auto curr=s.top();
        s.pop();
        if(curr){
            cout<<curr->data<<" ";
            s.push(curr->left);
            s.push(curr->right);
        }
    }
}
int main(){
    node* root=buildTree();
    //printprerec(root);
    preorder(root);
}