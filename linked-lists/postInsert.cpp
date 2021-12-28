

node *insertLast(int x , node *head) {
node *item = (node *)malloc(sizeof(node));
node * p=head;
while(p->next)
    p = p->next;
p->next = item ;
item->data =x;
item->next = NULL;

return head;

}
