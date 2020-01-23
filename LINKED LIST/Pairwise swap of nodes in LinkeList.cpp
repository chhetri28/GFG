struct Node* pairwise_swap(struct Node* head)
{
    // your code here    
    //a->b->c->d->e->f->null;


    Node*p,*q,*ns,*temp;
    p=head;
    ns=p->next;
    while(1){
        q=p->next;
        temp=q->next;
        q->next=p;
        if(temp==NULL || temp->next==NULL){
            p->next=temp;
            break;
        }
        p->next=temp->next;
        p=temp;

    }
}