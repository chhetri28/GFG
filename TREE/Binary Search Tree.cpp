#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d):data(d),left(NULL),right(NULL){}
};
node* insert(node* root,int data){
    if(root==NULL){
        return new node(data);
    }
    if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
bool search(node* root,int data){
    if(root==NULL){
        return false;
    }
    if(root->data==data){
        return true;
    }
    if(data<=root->data){
        return search(root->left,data);
    }
    else{
        return search(root->right,data);
    }
}
node* build(){
    int d;
    cin>>d;
    node* root=NULL;
    while (d!=-1)
    {
        root=insert(root,d);
        cin>>d;
    }
    return root;
}
node* pop(node* root,int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left=pop(root->left,data);
        return root;
    }
    else if(data>root->data){
        root->right=pop(root->right,data);
        return root;
    }
    else{
        // node with 0  children-Leaf node
        if(root->left==NULL and root->right==NULL){
            delete root;
            return NULL;
        }
        // node with 1 children
        if(root->left!=NULL and root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->right!=NULL and root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        //node with 2 children
        node* replace=root->right;
        // find the inorder successor from right subtree
        while(replace->left!=NULL){
            replace=replace->left;
        }
        root->data=replace->data;
        root->right=pop(root->right,replace->data);
        return root;
    }
}
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}
void bfs(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node* f=q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
int main(){
    node*root=build();
    bfs(root);
    cout<<endl; 
    root=pop(root,5);
   // bfs(root);
    root=pop(root,1);
    bfs(root);

}
//5 3 7 1 6 8 -1