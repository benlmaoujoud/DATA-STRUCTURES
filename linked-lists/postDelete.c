node *deleteLast(node *head){

node *tmp = NULL;
node *p = head;

while(p->next->next !=NULL)
    p = p->next ;
tmp = p->next;
p->next = NULL;
free(tmp);

return head;

}
