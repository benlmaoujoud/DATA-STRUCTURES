int ecart(node *head){

int d = head->next->data - head->data; 
node *p = head->next; 
    while(p->next != NULL && d==0){
        d = p->next->data - p->data;
        p=p->next; 
    }
    return d; 
}


bool isSorted(node *head) {
node *p = head;

int d =ecart(head);
while(p->next != NULL){
    if((d>0 && p->next->data - p->data <0) || (d<0 && p->next->data - p->data >0))
            return false;

    p=p->next;
}
return true;

}
