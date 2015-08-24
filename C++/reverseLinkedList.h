    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* dummy = new ListNode(-1), *cur = head;
        dummy->next = head;
        //1- 2- 3- 4
        while(cur->next){
            ListNode* tmpNode = cur->next;
            cur->next = cur->next->next;
            tmpNode->next = dummy->next;
            dummy->next = tmpNode;
        }
        return dummy->next;
    }