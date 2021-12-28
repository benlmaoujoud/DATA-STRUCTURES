

node *insertInPosition(int pos , int x , node *head){

node *item = (node*)malloc(sizeof(node));
if(pos == 0)
    head = insertFisrt(x, head);
else{
    node *p = head;
    for(int i = 0 ; i<pos-1; ++i){
        p = p->next;
    }
    item->next = p->next;
    p->next = item;
    item->data = x;
}

return head;
}
