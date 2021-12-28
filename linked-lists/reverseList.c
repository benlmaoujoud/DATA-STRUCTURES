node *reverseListe(node *head){

node *p = head;
node *tmp = NULL;
node *reverseListe = NULL ;

while(p!=NULL){
        tmp = (node*)malloc(sizeof(node)) ;
        tmp->data = p->data ;
        tmp->next = reverseListe;
        reverseListe= tmp;

        p = p->next;

}


return reverseListe ;
}
