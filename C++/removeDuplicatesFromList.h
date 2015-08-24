    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p,*q;
        if(head == NULL) return head;
        p = q = head;
        while(q != NULL &&q->next != NULL){
            if(q->val != q->next->val) q = q->next;
            else{
                p = q;
                while(q->next!= NULL && q->val == q->next->val) q = q->next;
                q = q->next;
                p->next = q;
            }
        }
        return head;
    }

    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p,*q;
        if(head == NULL) return head;
        p = head;
        q= head->next;
        
        while(q){
            if(p->val != q->val) p = q;
            else{
                ListNode* tmp;
                tmp = q;
                p ->next = q->next;
                delete tmp;
                q = p;
            }
            q = q->next;
        }
        return head;
    }    