
node *insertFisrt(int x , node *head){

node *item = (node*)malloc(sizeof(node));

item->next = head;
item->data = x;
head = item;

return head;
}
