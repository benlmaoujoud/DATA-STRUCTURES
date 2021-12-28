node *removeItem(int x , node *head){
node *tmp = NULL;
node *p =NULL;
if(head->data == x)
    deleteFirst(head);

    else {
            p=head;
            
            while(p!=NULL && p->next->data !=x){
                p = p->next;
            }
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
    }

    return head;

}
