node *deleteInPosition(int pos , node *head) {
    node *tmp = NULL;
node *p =NULL;
if(pos == 0)
    deleteFirst(head);

    else {
            p=head;
            int i=0 ;
            while(i<pos-1){
                p = p->next;
                ++i;
            }
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
    }

    return head;

}

