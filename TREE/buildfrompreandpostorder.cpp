#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
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
node* create(int *in,int *pre,int s,int e){
    static int i=0;
    if(s>e){
        return NULL;
    }
    node* root=new node(pre[i]);
    int index=-1;
    for(int j=s;j<=e;j++){
        if(in[j]==pre[i]){
            index=j;
            break;
        }
    }
    i++;
    root->left=create(in,pre,s,index-1);
    root->right=create(in,pre,index+1,e);
    return root;
}
int main(){
    //node*root=buildTree();
    int in[]={3,2,8,4,1,6,7,5};
    int pre[]={1,2,3,4,8,5,6,7};
    int n=sizeof(in)/sizeof(int);
    node* root=create(in,pre,0,n-1);
    bfs(root);
}