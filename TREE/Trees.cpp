#include<bits/stdc++.h>
using namespace std;
#define OJ \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
int height(node*root){
    if(root==NULL){
        return 0;
    }
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}
int diameter(node* root){
	if(!root)return 0;
	int d1=1+height(root->left)+height(root->right);
	int d2=diameter(root->left);
	int d3=diameter(root->right);
	return max(d1,max(d2,d3));
}
int res=0;
int diameter2(node* root){
	if(root==NULL) return 0;
	int lh=diameter2(root->left);
	int rh=diameter2(root->right);
	res=max(res,lh+rh+1);
	return 1+max(lh,rh);
}
void printkthlevel(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
        printkthlevel(root->left,k-1);
        printkthlevel(root->right,k-1);
        return;
}

void levelorder1(node*root){
    int H=height(root);
    for(int i=1;i<=H;i++){
        printkthlevel(root,i);
        cout<<endl;
    }
    return;
}
void levelorder2(node*root){
	if(root==NULL)return;
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		auto curr=q.front();
		q.pop();
		cout<<curr->data<<" ";
		if(curr->left)q.push(curr->left);
		if(curr->right)q.push(curr->right);
	}
	cout<<"\n";
}
void levelorder3(node*root){
	if(!root)return;
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		int c=q.size();
		for(int i=0;i<c;i++){
			auto curr=q.front();
			q.pop();
			cout<<curr->data<<" ";
			if(curr->left)q.push(curr->left);
			if(curr->right)q.push(curr->right);
		}
		cout<<"\n";
	}
}
int getmaxi(node* root){
	if(root==NULL)return INT_MIN;
	int maxi1=getmaxi(root->left);
	int maxi2=getmaxi(root->right);
	return max(root->data,max(maxi1,maxi2));
}
void printLeft(node* root){
	if(!root)return;
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		int c=q.size();
		for(int i=0;i<c;i++){
			auto curr=q.front();
			q.pop();
			if(i==0){
			cout<<curr->data<<" ";
			}
			if(curr->left)q.push(curr->left);
			if(curr->right)q.push(curr->right);
		}
	}
}
void printRight(node* root){
	if(!root)return;
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		int c=q.size();
		for(int i=0;i<c;i++){
			auto curr=q.front();
			q.pop();
			if(i==0){
				cout<<curr->data<<" ";
			}
			if(curr->right)q.push(curr->right);
			if(curr->left)q.push(curr->left);
		}
	}
}
int maxlevel=0;
void printright(node* root,int level){
	if(!root)return;
	if(maxlevel<level){
		cout<<root->data<<" ";
		maxlevel=level;
	}
	printright(root->right,level+1);
	printright(root->left,level+1);
}
void printR(node* root){
	printright(root,1);
}

bool ischildsum(node* root){
	if(root==NULL)return true;
	if(root->left!=NULL and root->right!=NULL)return true;
	int sum=0;
	if(root->left!=NULL)sum+=root->left->data;
	if(root->right!=NULL)sum+=root->right->data;
	return root->data==sum and ischildsum(root->left) and ischildsum(root->right);
}
bool balancedtree(node* root){
	if(root==NULL)return true;
	int lh=height(root->left);
	int rh=height(root->right);
	int d=abs(lh-rh);
	return d<=1 and balancedtree(root->left) and balancedtree(root->right);
}
int balancedtree2(node* root){
	if(root==NULL)return 0;
	int lh=balancedtree2(root->left);
	if(lh==-1)return -1;
	int rh=balancedtree2(root->right);
	if(rh==-1)return -1;
	if(abs(lh-rh)>1)return -1;
	else return max(lh,rh)+1;
}
int maxwidth(node* root){
	if(root==NULL)return 0;
	queue<node*>q;
	q.push(root);
	int res=0;
	while(!q.empty()){
		int c=q.size();
		res=max(res,c);
		for(int i=0;i<c;i++){
			auto curr=q.front();
			q.pop();
			if(curr->left)q.push(curr->left);
			if(curr->right)q.push(curr->right);
		}
	}
	return res;
}
int preindex=0;
node* ctreehelper(int in[],int pre[],int is,int ie,unordered_map<int,int>&mp){
	if(is>ie)return NULL;
	int curr=pre[preindex++];
	node* root=new node(curr);
	if(is==ie)return root;
	int index=mp[curr];
	root->left=ctreehelper(in,pre,is,index-1,mp);
	root->right=ctreehelper(in,pre,index+1,ie,mp);
	return root;
}
node* ctree(int in[],int pre[],int len){
	unordered_map<int,int>mp;
	for(int i=0;i<len;i++){
		mp[in[i]]++;
	}
	node* root=ctreehelper(in,pre,0,len-1,mp);
	return root;
}
void spiral(node* root){
	if(root==NULL) return;
	queue<node*>q;
	q.push(root);
	stack<int>s;
	int rev=false;
	while(!q.empty()){
		int c=q.size();
		for(int i=0;i<c;i++){
			auto curr=q.front();
			q.pop();
			if(rev){
				s.push(curr->data);
			}else{
				cout<<curr->data<<" ";
			}
			if(curr->left!=NULL)q.push(curr->left);
			if(curr->right!=NULL)q.push(curr->right);
		}
		if(rev){
			while(!s.empty()){
				cout<<s.top()<<" ";
				s.pop();
			}
		}
		rev=!rev;
	}
}
void spiral2(node*root){
	stack<node*>s1,s2;
	s1.push(root);
	while(!s1.empty()||!s2.empty()){
		while(!s1.empty()){
			auto curr1=s1.top();
			s1.pop();
			cout<<curr1->data<<" ";
			if(curr1->left)s2.push(curr1->left);
			if(curr1->right)s2.push(curr1->right);
		}
		while(!s2.empty()){
			auto curr1=s2.top();
			s2.pop();
			cout<<curr1->data<<" ";
			if(curr1->right)s1.push(curr1->right);
			if(curr1->left)s1.push(curr1->left);
		}
	}
}
int countnodes(node* root){
	int c=0;
	if(root==NULL)return 0;
	c=1+countnodes(root->left)+countnodes(root->right);
	return c;
} 
node* LCA(node* root,int a,int b){
	if(root==NULL)return NULL;
	if(root->data==a||root->data==b){
		return root;
	}
	node* left=LCA(root->left,a,b);
	node* right=LCA(root->right,a,b);
	if(left!=NULL and right!=NULL){
		return root;
	}
	if(left!=NULL)return left;
	return right;
}
int searchlevel(node* root,int key,int level){
	if(root==NULL)return -1;
	if(root->data==key)return level;
	int left=searchlevel(root->left,key,level+1);
	if(left==-1){
		return left;
	}
	return searchlevel(root->right,key,level+1);
}
int distancetwonodes(node* root,int a,int b){
	node* lca_node=LCA(root,a,b);
	int l1=searchlevel(lca_node,a,0);
	int l2=searchlevel(lca_node,b,0);
	return l1+l2;
}
//iterative 
void preorder1(node*root){
	if(root==NULL)return;
	stack<node*>s1;
	s1.push(root);
	while(!s1.empty()){
		auto curr=s1.top();
		s1.pop();
		cout<<curr->data<<" ";
		if(curr->right)s1.push(curr->right);
		if(curr->left)s1.push(curr->left);
	}
}
void postorder1(node* root){
	if(root==NULL)return;
	stack<node*>s1,s2;
	s1.push(root);
	while(!s1.empty()){
		auto curr=s1.top();
		s1.pop();
		s2.push(curr);
		if(curr->left)s1.push(curr->left);
		if(curr->right)s1.push(curr->right);
	}
	while(!s2.empty()){
		auto curr=s2.top();
		s2.pop();
		cout<<curr->data<<" ";
	}
	return;	
}

void inorder1(node* root){
	stack<node*>s;
	auto curr=root;
	while(curr!=NULL || !s.empty()){
		while(curr!=NULL){
			s.push(curr);
			curr=curr->left;
		}
		curr=s.top();
		s.pop();
		cout<<curr->data<<" ";
		curr=curr->right;
	}
}

// recursive traversal
void postorder(node*root){
	if(!root)return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
void preorder(node*root){
	if(!root)return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(node*root){
	if(!root)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void rinorder(node*root){
	if(!root)return;
	rinorder(root->right);
	cout<<root->data<<" ";
	rinorder(root->left);
}
// path between the given nodes
bool getpath(node* root,vector<int>&path,int a){
	if(!root)return false;// if root is null there is no path
	path.push_back(root->data);//push the node value in the array
	//if the required node is our data then return true
	if(root->data==a){
		return true;
	}
	//else check for left and right
	if(getpath(root->left,path,a)||getpath(root->right,path,a)){
		return true;
	}
	//if not present delete the last node from array
	path.pop_back();
	return false;

}
void printpath(node* root,int a,int b){
	vector<int>p1;
	vector<int>p2;
	getpath(root,p1,a);
	getpath(root,p2,b);
	int intersection=-1;
	int i=0,j=0;
	while(i!=p1.size()||j!=p2.size()){
		if(i==j and p1[i]==p2[j]){
			i++;
			j++;
		}else{
			intersection=j-1;
			break;
		}
	}
	for(int i=p1.size()-1;i>intersection;i--){
		cout<<p1[i]<<" ";
	}
	for(int i=intersection;i<p2.size();i++){
		cout<<p2[i]<<" ";
	}
}
void serialize(node*root,vector<int>&vec){
	if(root==NULL){
		vec.push_back(-1);
		return;
	}
	vec.push_back(root->data);
	serialize(root->left,vec);
	serialize(root->right,vec);
}
int i=0;
node*deserialize(vector<int>&vec){
	if(i==vec.size()){
		return NULL;
	}
	int val=vec[i++];
	if(val==-1)return NULL;
	node* temp=new node(val);
	temp->left=deserialize(vec);
	temp->right=deserialize(vec);
	return temp;
}
int sum=0;
void sumAtlevelK(node* root,int k)
{
  if(root==NULL)
    return;
  if(k==0)
    sum+=root->data;
  if(k<1)
    return;
  
  sumAtlevelK(root->left,k-1);
  sumAtlevelK(root->right,k-1);
}
void fun(int *a,int n){
int prev=INT_MIN;
int first=0,second=0;
	for(int i=0;i<n;i++){
		if(a[i]<prev){
			if(first==0){
				first=prev;
			}
			second=a[i];	
		}
		prev=a[i];
	}
	cout<<first<<" "<<second;
}
int main(){
	OJ;
	FIO;
	int n; 	
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	fun(a,n);
	// int in[]={20,10,40,30,50};
	// int pre[]={10,20,30,40,50};
	// int len=sizeof(in) / sizeof(in[0]); 
	// node* root=ctree(in,pre,len);
    // node*root=buildTree();
	// rinorder(root);
	// sumAtlevelK(root,2);
	// cout<<sum;
	// levelorder1(root);
	// levelorder2(root);
	// levelorder3(root);
	// vector<int>vec;
	//serialize(root,vec);
	// for(int i=0;i<13;i++){
	// 	int x;
	// 	cin>>x;
	// 	vec.push_back(x);
	// }
	// node*root=deserialize(vec);
	//printpath(root,9,5);
	// inorder1(root);
	// postorder(root);
	//preorder1(root);
	//inorder(root);
	// cout<<diameter2(root);
	//cout<<countnodes(root);
	//int k=height(root);mm
	//spiral2(root);	
	//cout<<getmaxi(root);
	//printright(root);
	//printR(root);
	//printRight(root);
	//leftside(root);
	//printLeft(root);
	//ischildsum(root);
	//cout<<balancedtree(root);
	//cout<<balancedtree2(root);
	//cout<<maxwidth(root);
}