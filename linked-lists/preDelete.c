node *deleteFirst(node *head){

node *tmp ;
tmp = head;
head = tmp->next ;
free(tmp);
return head;

}

