int getDecimalValue(struct ListNode* head){

    int d = count(head) ; 
    
    struct ListNode *p = head ;
    int sum = 0 ; 
    while(p != NULL && d>0){
         sum = sum +power(2,d-1)*p->val ;
         d-- ; 
         p = p->next ; 
    }
    
    return sum ; 
}
