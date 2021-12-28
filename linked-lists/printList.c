

void printListe(node *head){
node *p = head;

while(p){
    printf("%d ->",p->data);
    p = p->next;
}
printf("NULL");

}

