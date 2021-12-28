int countNodes(node *head) {
    if (head == NULL)
        return 0;
    else
        return 1 + countNodes(top -> next);
}
