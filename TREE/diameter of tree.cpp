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
/*node* buildTreeLevelWise(){
    int d;
    cin>>d;
    node* root=new node(d);
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int c1,c2;
        cin>>c1>>c2;
        node* f=q.front();
        q.pop();
        if(c1!=-1){
            f->left=new node(c1);
            q.push(f->left);
        }
        if(c2!=-1){
            f->right=new node(c2);
            q.push(f->right);
        }
    }
    return root;
}*/
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
int height(node * root)
{
   // Your code here
   if(root==NULL){
       return 0;
   }
   int ls=height(root->left);
   int rs=height(root->right);
   return max(ls,rs)+1;
}

int diameter(node*root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    int op1=h1+h2;
    
    int op2=diameter(root->left);
    int op3=diameter(root->right);

    return max(op1,max(op2,op3));
}
int main(){
 node* root=buildtree();
 cout<<diameter(root);
}