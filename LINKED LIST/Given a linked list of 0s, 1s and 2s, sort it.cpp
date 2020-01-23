Node* segregate(Node *head) {
    
    // Add code here
    Node*temp=head;
    int c0=0,c1=0,c2=0;
    while(temp!=NULL){
        if(temp->data==0){
            c0++;
        }
        else if(temp->data==1){
            c1++;
        }
        else{
            c2++;
        }
        temp=temp->next;
    }
    Node*temp2=head;
    for(int i=0;i<c0;i++){
        temp2->data=0;
        temp2=temp2->next;
    }
    for(int i=0;i<c1;i++){
        temp2->data=1;
        temp2=temp2->next;
    }
    for(int i=0;i<c2;i++){
        temp2->data=2;
        temp2=temp2->next;
    }
    return head;
}