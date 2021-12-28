node *insertOrder(int x , node *head){

node *p = head;
node *tmp = (node*)malloc(sizeof(node));
tmp->data = x;
while(p->next !=NULL) {
    if(p->data < x && p->next->data >x){
            tmp->next =p->next;
            p->next = tmp;
    }
    p = p->next;
}

return head;

}
