    ListNode *insertionSortList(ListNode *head) {
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* cur = dummy;
        
        while(cur && cur->next){
            if(cur->val > cur->next->val){ //insert cur->next
                ListNode * tmp = cur->next;
                cur->next = cur->next->next;
                insert(dummy,tmp);
            }else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
    void insert(ListNode* head, ListNode* node){
        ListNode *p = head;
        while(p && p->next){
            if(p->next->val < node->val) p = p->next;
            else break;
        }
        node->next = p->next;
        p->next = node;
    }

    //
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* dummy = new ListNode(-1), *cur = head->next;
        ListNode* pre = dummy;
        dummy->next = head;
        dummy->next->next = NULL;
        
        while(cur){
            ListNode* tmp = cur;
            cur = cur->next;
            while(pre->next && pre->next->val <= tmp->val) pre = pre->next;
            tmp->next = pre->next;
            pre->next = tmp;
            pre = dummy;
        }
        return dummy->next;
    }