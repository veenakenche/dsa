/** * Definition for singly-linked list. * struct ListNode { *     int val; *     struct ListNode *next; * }; */   struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
     if(headA == NULL || headB == NULL) return NULL;

    struct ListNode * t1 = headA, * t2 = headB;

    while(t1 != t2){
        t1 = t1 -> next;
        t2 = t2 -> next;

        if(t1 == t2) return t1;

        if(t1 == NULL) t1 = headB;
        if(t2 == NULL) t2 = headA;
    }
    return t1;}