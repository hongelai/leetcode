    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* dummy  = new ListNode(-1), *fast, *slow;
        dummy->next = head;
        fast = slow = dummy;
        while(fast){
            if(fast && fast->val == val){
                slow->next = slow->next->next;
                delete fast;
                fast = slow->next;
            } else {
                slow = fast;
                fast = fast->next;
            }
        }
        return dummy->next;
    }