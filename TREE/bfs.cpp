#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
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

// void bfs(node* root){
//     queue<node*>q;
//     q.push(root);
//     q.push(NULL);
//     while (!q.empty())
//     {
//         node* f=q.front();
//         if(f==NULL){
//             cout<<endl;
//             q.pop();
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//         else{
//             cout<<f->data<<" ";
//             q.pop();
//             if(f->left){
//                 q.push(f->left);
//             }
//             if(f->right){
//                 q.push(f->right);
//             }
//         }
//     }
//     return;
// }

void bfs2(node* root){
    if(root==NULL) return;
    else{
        queue<node*>q;
        q.push(root);
        while(q.size()>0){
            int cnt=q.size();
            while(cnt>0){
                node* f=q.front();
                q.pop();
                cout<<f->data<<" ";
                if(root->left!=NULL){
                    q.push(f->left);
                }
                if(root->right!=NULL){
                    q.push(f->right);
                }
                cnt--;
            }
            cout<<endl;
        }
    }
}
int main(){
    node*root=buildTree();
    bfs2(root);
}
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1