    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* post = dummy, *pre = dummy->next;
        
        while(pre && pre->next){
            //swap nodes
            ListNode* tmp = pre->next;
            pre->next = pre->next->next;
            post->next = tmp;
            tmp->next = pre;
            
            //move forward
            post = pre;
            pre = pre->next;
        }
        return dummy->next;
    }