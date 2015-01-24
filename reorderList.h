    void reorderList(ListNode *head) {
        //find the mid node, cut the list into two from half and reverse. And then combine
        if(head == NULL || head->next == NULL) return;
        ListNode* fast, * slow;
        fast = head->next->next; slow = head;
        
        //find mid
        while(fast){
            slow = slow->next;
            if(fast->next && fast->next->next) fast = fast->next->next;
            else break;
        }
        
        //cut list into two, slow....., fast.....
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        
        //reverse second list
        ListNode* dummy = new ListNode(-1);
        dummy->next = fast;
        ListNode *pre;
        pre = dummy->next;
        while(pre && pre->next){
            ListNode *tmp = pre->next;
            pre->next = pre->next->next;
            tmp->next = dummy->next;
            dummy->next = tmp;
        }
        fast = dummy->next;
        
        //merge two list
        ListNode * pt = new ListNode(-1);
        dummy = pt;
        
        while(fast && slow){
            pt->next = slow;
            slow = slow->next;
            pt = pt->next;
            pt->next = fast;
            fast = fast->next;
            pt = pt->next;
        }
        pt->next = slow;
        head = dummy->next;
    }