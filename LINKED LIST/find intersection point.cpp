int length(Node*start){
    int l=0;
    while(start!=NULL){
        l++;
        start=start->next;
    }
    return l;
} 
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node*l,*s;// make two node large and small
    int l1=0,l2=0;
    int d=0;
    // take the length of both node
    l1=length(head1);
    l2=length(head2);
    d=abs(l1-l2);// take the difference
    if(l1>l2){//compare  which is bigger and assign the large and small
        l=head1;
        s=head2;
    }
    else{
        l=head2;
        s=head1;
    }
    // move the large d steps ahead
    for(int i=0;i<d;i++){
        l=l->next;
    }
    //loop till large==small and move 1 by 1
    while(l!=s){
        l=l->next;
        s=s->next;
    }
    //large data
    return l->data;
}
Node *getintersect(Node* head1,Node* head2){
    Node *p1=head1;
    Node *p2=head2;
    if(p1==NULL || p2==NULL) return NULL;
    while(p1!=NULL and p2!=NULL and p1!=p2){
        p1=p1->next;
        p2=p2->next;
        //any time they collide or reach end together without colliding
        //then return any one of the pointers
        if(p1==p2) return p1;
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        if(p1==NULL)p1=headB;
        if(p2==NULL)p2=headA;
    }
    return p1;
}