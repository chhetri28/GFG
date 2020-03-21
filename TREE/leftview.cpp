#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d):data(d),left(NULL),right(NULL){}
};
node* buildTreeLevelWise(){

	int d;
	cin>>d;

	node*root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){

		node*f = q.front();
		q.pop();
		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			f->left = new node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new node(c2);
			q.push(f->right);
		}
	}
	return root;
}


void helper(node*root,int level,int *max_level){
    if(!root)return;
    if(level>*max_level){
        cout<<root->data<<" ";
        *max_level=level;
    }
    helper(root->left,level+1,max_level);
    helper(root->right,level+1,max_level);
}
void leftside(node*root){
    int max_level=0;
    helper(root,1,&max_level);
}
int main(){
    node* root=buildTreeLevelWise();
    lefttside(root);
}