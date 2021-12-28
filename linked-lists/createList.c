

node *createList(int n , node *head){ ///many Nodes 

node * tmp = NULL ;
node * p = NULL;
int x;
    for(int i = 0 ; i<n ; ++i) {
        tmp = (node*)malloc(sizeof(node));
        printf("Node Number %d  : ",i);
        scanf("%d",&x);
        tmp->data = x;
        tmp->next = NULL;
        if(head == NULL)
            head = tmp;
        else{
            p = head;
            while(p->next != NULL)
                p = p->next;
            p->next = tmp;
        }

    }

    return head;
}
