    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m == n) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *pre,*pos;
        pre = pos = dummy;
        int index = 0;
        
        while(index++ < m-1) pre = pre->next; // locate pre to m-1
        pos = pre->next; // locate pos to m
        
        while(index++ < n){
            ListNode* tmp = pos->next;
            pos->next = pos->next->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return dummy->next;
        
    }