#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d):data(d),left(NULL),right(NULL){}
};
node* buildTreeFromArray(int *a,int s,int e){
    //Base Case
    if(s>e){
        return NULL;
    }
    //Recursive Case
    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = buildTreeFromArray(a,s,mid-1);
    root->right = buildTreeFromArray(a,mid+1,e);
    return root;
}
void top(node* root){
    if(!root) return;

    unordered_map<int,int >m;
    queue<pair<node*,int> >q;
    //push node and horizontal distance
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int>p=q.front();
        node *n=p.first;
        int val=p.second;
        q.pop();
        if(m.find(val)==m.end()){
            m[val]=n->data;
            cout<<n->data;
        }
        if(n->left!=NULL){
            q.push(make_pair(n->left,val-1));
        }
        if(n->right!=NULL){
            q.push(make_pair(n->right,val+1));
        }
    }
}
int main(){
    int n; 
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    node* root=buildTreeFromArray(a,0,n-1);
    top(root);
}