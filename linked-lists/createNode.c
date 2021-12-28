

node *newNode(int x){
    node *head = (node*)malloc(sizeof(node));/* allocates physical memory for the node */
    head->data = x;
    head->next = NULL;

    return head;

}
