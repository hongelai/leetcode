    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast,*slow;
        ListNode dummy{-1}; //不能初始化为指针，因为没有内存 ，
                            // 可以用struct PipeShm * myPipe = &(struct PipeShm) {
                            //             .val = 0, //val 前面要加点
                            //             /* ... */
                            //         };
        dummy.next = head;
        fast = slow = &dummy;
        for(int i = 0; i < n; i++) 
            fast = fast->next;
            
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        
        return dummy.next;
    }