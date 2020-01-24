struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    node*curr=head;
    node*prev=NULL;
    node*n;
    int count=0;
    while(curr!=NULL and count<k){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
        count++;
    }
    if(n!=NULL){
        head->next=reverse(n,k);
    }
    return prev;
}
