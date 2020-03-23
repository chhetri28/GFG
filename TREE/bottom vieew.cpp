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
node* buildtreelevelwise(){
	int d;
	cin>>d;
	node* root=new node(d);
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node*f=q.front();
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
void bottomView(node *root) 
{ 
    if (root == NULL) 
        return; 
   
    int hd = 0; 
   
    map<int, int> m; 
  
    queue<node *> q;  
    root->hd = hd; 
    q.push(root);  
    while (!q.empty()) 
    { 
        node *temp = q.front(); 
        q.pop();   
   
        hd = temp->hd; 
  
        
        m[hd] = temp->data; 
  
   
        if (temp->left != NULL) 
        { 
            temp->left->hd = hd-1; 
            q.push(temp->left); 
        } 
  
  
        if (temp->right != NULL) 
        { 
            temp->right->hd = hd+1; 
            q.push(temp->right); 
        } 
    } 
  
    
    for (auto i = m.begin(); i != m.end(); ++i) 
        cout << i->second << " "; 
} 
int main() {
	node* root=buildtreelevelwise();
	bottomView(root);
	return 0;
}