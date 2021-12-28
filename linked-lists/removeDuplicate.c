

node *removeDupliacate(node *head){

node *p = head;
node *q = head->next;

while(q != NULL) {
    if(p->data != q->data){
        p = q ;
        q = q->next;
    }
    else{


        p->next = q->next;
        free(q);
        q = p->next;
    }

}
return head;

}
