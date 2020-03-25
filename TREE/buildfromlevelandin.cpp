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
node* create(int *in,int *lv,int s,int e){
    static i=0;
    if(s>e){
        return NULL;
    }
    node* root=new node(lv[i]);
    int index=-1;
    for(int j=s;j<=e;j++){
        if(lv[0]==in[j]){
            index= j;
            break;
        }
    }
    i++;
    root->left=create(in,lv,s,index-1);
    root->right=create(in,lv,index+1,e);
    return root;
}                               

int main(){
    int in[] = {4, 8, 10, 12, 14, 20, 22};
    int lv[] = {20, 8, 22, 4, 12, 10, 14};
    int n=sizeof(in)/sizeof(int);
    node* root=create(in,lv,0,n-1);
    bfs(root);
}