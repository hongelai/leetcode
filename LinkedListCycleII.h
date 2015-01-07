    ListNode *detectCycle(ListNode *head) {
        //http://www.cnblogs.com/x1957/p/3406448.html
        ListNode* fast,*slow;
         fast = slow = head;
         
         while(fast && fast->next){
             fast = fast->next->next;
             slow = slow->next;
             if(fast == slow){ //found cycle
                 fast = head;
                 while(fast != slow){
                     fast = fast->next;
                     slow = slow->next;
                 }
                 
                 return fast;
             } 
         }
         return NULL;
    }