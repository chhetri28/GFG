#include<bits/stdc++.h>
using namespace std;
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Node{
    public:
    int data;
    Node*next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
int length(Node*head){
    int cnt(0);
    Node* curr=head;
    while(curr!=NULL){
        curr=curr->next;
        cnt++;
    }
    return cnt;
}
// returning node using reference 
void insertinhead(Node*&head,int data){
    if(head==NULL){
        head=new Node(data);
        return;
    }
    Node* n=new Node(data);
    n->next=head;
    head=n;
}
void insertintail(Node*&head,int data){
    if(head==NULL){
        Node* n=new Node(data);
    }
    Node*curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=new Node(data);
}
void insertinmiddle(Node*&head,int data,int p){
    if(p==0 || head ==NULL){
        insertinhead(head,data);
        return;
    }
    else if(p>length(head)){
        insertintail(head,data);
    }
    else{
        int jump=1;
        Node* curr=head;
        while(jump<=p-1){
            curr=curr->next;
            jump++;
        }
        Node* n=new Node(data);
        n->next=curr->next;
        curr->next=n;
    }
    return;
}
void printll(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<'\n';
}
int main(){
    OJ;
    FIO;
    Node*head=NULL;
    int n;
    cin>>n;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        insertinhead(head,data);
    }
    insertintail(head,6);
    insertinmiddle(head,8,2);;
    printll(head);
    //cout<<length(head);
}