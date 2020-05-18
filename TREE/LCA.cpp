#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Custom{
    public:
    bool hasKey1;
    bool hasKey2;
    TreeNode* node;

};
Custom* helper(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL) return NULL;
    //check for lst and rst
    Custom* leftans=helper(root->left,p,q);
    if(leftans!=NULL and leftans->node!=NULL){
        return leftans;
    }
    Custom* rightans=helper(root->right,p,q);
    if(rightans!=NULL and rightans->node!=NULL){
        return rightans;
    }
    //check for one of them are in ur rst and other is in our rst
    Custom* result =new Custom();
    if( leftans!=NULL and rightans!=NULL){
        result->node=root;
        result->hasKey1=true;
        result->hasKey2=true;
        return result;
    }else if(root->val==p->val){
        result->hasKey1=true;
        result->hasKey2=(leftans)?leftans->hasKey2:false or (rightans)?rightans->hasKey2:false;
        if(result->hasKey1 and result->hasKey2) result->node=root;
        return result;
    }
    else if(root->val==q->val){
        result->hasKey2=true;
        result->hasKey1=(leftans)?leftans->hasKey1:false or (rightans)?rightans->hasKey1:false;
        if(result->hasKey1 and result->hasKey2) result->node=root;
        return result;
    }else if(leftans){
        return leftans;
    }
    else if(rightans){
        return rightans;
    }
    return NULL;
}

TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    Custom* result=helper(root,p,q);
    if(result==NULL) return NULL;
    else return result->node;
}
int main(){


    return 0;
}