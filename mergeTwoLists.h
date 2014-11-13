    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

        ListNode* newlist;
        ListNode head{-1};
        newlist = &head;
        while(l1!=NULL && l2!=NULL){
            if(l1->val > l2->val){
                newlist->next = l2;
                l2 = l2->next;
            }else{
                newlist->next = l1;
                l1 = l1->next;
            }
            newlist = newlist->next;
        }
        if(l1) newlist->next = l1;
        if(l2) newlist->next = l2;
        return head.next;
    }