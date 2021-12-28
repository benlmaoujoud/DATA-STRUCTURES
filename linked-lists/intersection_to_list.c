int count(struct ListNode *head ){
    if(head == NULL)
        return 0 ; 
    return 1+ count(head->next) ; 
    
}

int  abs(int x){
    if(x <0)
        return -x ;
    return x ; 
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)   
{
        if(headA == NULL && headB == NULL)
            return NULL ; 
        int a = count(headA); 
        int b = count(headB); 
        int d = abs(a-b); 
                                     
        struct ListNode *p = headA; 
        struct ListNode *q = headB; 
        while(d>0){
            if(a>b)
                p = p->next ; 
            else
                q = q->next ; 
        d--;     
        }
        while(p != q){
            p = p->next ; 
            q = q->next ; 
        }

    return p ;            
}

