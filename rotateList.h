    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *fast, * slow;
        slow = fast = head;
        for(int i = 0; i < k; i++){
            fast = fast->next;
            if(fast == NULL) fast = head;
        }
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *pre, *post;
        pre = slow; post = dummy;
        
        while(pre && pre->next){
            ListNode* tmp = pre->next;
            pre->next = pre->next->next;
            tmp->next = post->next;
            post->next = tmp;
            post = post->next;
        }
        return dummy->next;
    }