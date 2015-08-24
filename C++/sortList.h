    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        //use fast and slow pointer to find the mid
        ListNode *fast, *slow;
        fast = slow = head;
        
        while(fast && fast->next){ 
            fast = fast->next->next;
            if(fast) slow = slow->next; // use if() to handle 1->2->null
        }
        
        //seperate into two lists
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return merge(l1,l2);
    }
    ListNode *merge(ListNode *first, ListNode *second){
    
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        
        while(first && second){
            if(first->val < second->val){
                p->next = first;
                first = first->next;
            }else{
                p->next = second;
                second = second->next;
            }
            p = p->next;
        }
        if(first) p->next = first;
        else p->next = second;
        
        return dummy->next;
    }