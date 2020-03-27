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
node* buildTreeLevelWise(){
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
}
void get(node* root,int hd,map<int,vector<int>>&mp){
    if(!root) return;

    mp[hd].push_back(root->data);
    get(root->left,hd-1,mp);
    get(root->right,hd+1,mp);
}
void verticalorder(node* root){
 map<int,vector<int> >mp;
 int hd=0;
 get(root,hd,mp);
map< int,vector<int> > :: iterator it; 
    for (it=mp.begin(); it!=mp.end(); it++) 
    { 
        for (int i=0; i<it->second.size(); ++i) 
            cout << it->second[i] << " "; 
        cout << endl; 
    } 
}
int main(){
 node* root=buildTreeLevelWise();
 verticalorder(root);
}