void remove(Node* head,Node* f)
{
    Node* s=head;// head->s;
    while(s!=f)//traverse till fast and slow meet
    {
        //move one by one
        s=s->next;
        f=f->next;
    }
    
    while(s->next!=f)
        s=s->next;
    
    s->next=NULL;
    
}

void removeTheLoop(Node *head)
{
     Node* s=head,*f=head;
     
     while(s&&f&&f->next)
     {
         f=f->next->next;
         s=s->next;
         if(s==f)
         {
             remove(head,f);
             return;
         }
     }
}
