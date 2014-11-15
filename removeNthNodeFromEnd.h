    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast,*slow;
        ListNode dummy{-1}; //ListNode * dummy = new(-1);
        dummy.next = head;
        fast = slow = &dummy;
        for(int i = 0; i < n; i++) 
            fast = fast->next;
            
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        
        return dummy.next;
    }