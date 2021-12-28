node *mergeTwoListe(node *head1 , node *head2) {

node *head = (node*)malloc(sizeof(node));
node *curr = head;
node *p = head1 ;
node *q = head2 ;


while(p != NULL && q != NULL) {

    if(p->data > q->data){
        curr->next = q;
        q = q->next ;
    }
    else{
        curr->next =p;
        p = p->next ;
    }

    curr = curr->next;
}

if(p == NULL){
    curr->next = q;
}
else
    curr->next = p;

head =head->next;

return head ;
}
