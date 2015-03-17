    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || !head->next) return head;

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
        //cut after slow pointer head...slow, ....fast->NULL
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
    
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode *p = head, *fast, *slow;
        int len = 1;
        while(p->next){
            len++;
            p = p->next;
        }
        k %= len;
        fast = slow = head;
        while(k){
            fast = fast->next;
            k--;
        }
        while(fast && fast->next){
            fast = fast->next;
            slow = slow->next;
        } 
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        
        return head;
    }