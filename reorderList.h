    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL) return;
        ListNode *fast, *slow;
        slow = head, fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //reverse second half
        fast = slow->next;
        while(fast->next){
            ListNode* tmp = fast->next;
            fast->next = fast->next->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        
        //seperate and then merge 
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        while(fast){
            ListNode* tmp = fast;
            fast = fast->next;
            tmp->next = slow->next;
            slow->next = tmp;
            slow = slow->next->next;
        }
    }