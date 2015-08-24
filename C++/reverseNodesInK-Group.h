    ListNode *reverseKGroup(ListNode *head, int k) {
        
        if(k <= 1 || head == NULL) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        //initialize pointer
        ListNode *post, *pre, *test;
        post = test = dummy; pre = dummy->next;

        int index = 0;
        while(pre && pre->next){
            //detect size
            index = 0;
            while(index++ < k && test != NULL){
                test = test->next;
            }
            if(index < k || test == NULL) break;
            
            index = 0;
            while(index++ < k-1){
                ListNode* tmp = pre->next;
                pre->next = pre->next->next;
                tmp->next = post->next;
                post->next = tmp;
            }
            post = test = pre;
            pre = pre->next;
        }
        return dummy->next;
    }
    //more smart way to avoid detect size
    //reverseTimes = getLenth(head) / k