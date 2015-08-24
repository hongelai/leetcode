    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        
        ListNode *fast,*slow;
        fast = head->next->next;
        slow = head;
        while(fast != NULL){
            if(fast == slow) return true;
            else{
                if(fast->next == NULL )return false;
                else{
                    fast = fast->next->next;
                    slow = slow->next;
                }
            }
        }
        return false;
        
    }