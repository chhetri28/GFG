#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    int hd;
    node* left;
    node* right;
    node(int d):data(d),left(NULL),right(NULL){}
};
node* buildTreeLevelWise(){
    int d;
    cin>>d;
    node *root=new node(d);
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* f=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
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
}

// void top(node* root){
//     if(!root) return;

//     unordered_map<int,int >m;
//     queue<pair<node*,int> >q;
//     //push node and horizontal distance
//     q.push(make_pair(root,0));
//     while(!q.empty()){
//         pair<node*,int>p=q.front();
//         node *n=p.first;
//         int val=p.second;
//         q.pop();
//         if(m.find(val)==m.end()){
//             m[val]=n->data;
//             cout<<n->data;
//         }
//         if(n->left!=NULL){
//             q.push(make_pair(n->left,val-1));
//         }
//         if(n->right!=NULL){
//             q.push(make_pair(n->right,val+1));
//         }
//     }
// }
void top(node* root) 
{ 
    if(root==NULL) 
       return; 
     queue<node*>q; 
     map<int,int> m;  
     int hd=0; 
     root->hd=hd; 
       
     // push node and horizontal distance to queue 
    q.push(root); 
      
      
    while(q.size()) 
    { 
        hd=root->hd; 
          
        // count function returns 1 if the container  
        // contains an element whose key is equivalent  
        // to hd, or returns zero otherwise. 
        if(m.count(hd)==0)   
        m[hd]=root->data; 
        if(root->left) 
        { 
            root->left->hd=hd-1; 
            q.push(root->left); 
        } 
        if(root->right) 
        { 
            root->right->hd=hd+1; 
            q.push(root->right); 
        } 
        q.pop(); 
        root=q.front(); 
        
    } 
      
      
      
     for(auto i=m.begin();i!=m.end();i++) 
    { 
        cout<<i->second<<" "; 
    } 
      
} 
int main(){
    node* root=buildTreeLevelWise();
    top(root);
}