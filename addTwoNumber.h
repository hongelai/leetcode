    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy{-1};
        ListNode* newlist;
        newlist = &dummy;
        int carry =0;
        while(l1 || l2 || carry){
            int val = 0;
            if(l1){
                val += l1->val;
                l1 = l1->next;
            }
            if(l2){
                val+= l2->val;
                l2 = l2->next;
            }
            val+= carry;
            carry = val/10;
            if(val > 9) val %=10;
            ListNode* tmp = new ListNode(val); //不能用ListNode tmp{-1} , 是临时对象会被释放 
            newlist->next = tmp;
            newlist = newlist->next;
        }

        return dummy.next;
    }