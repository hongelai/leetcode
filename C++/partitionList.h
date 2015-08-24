    ListNode *partition(ListNode *head, int x) {
        if(!head) return NULL;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *post, *pre;
        post = dummy; pre = dummy;
        
        while(pre && pre->next){
            if(pre->next->val >= x){
                pre = pre->next;
            } 
            else{
                if(post != pre){
                    ListNode* tmp = pre->next;
                    pre->next = pre->next->next;
                    tmp->next = post->next;
                    post->next = tmp;
                    //forward
                    post = post->next;
                }else{
                    //forward
                    post = post->next;
                    pre = pre->next;
                }
            }
            
            
        }
        return dummy->next;
    } 