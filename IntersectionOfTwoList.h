    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA,*p2 = headB;
        if(p1 == NULL || p2 == NULL) return NULL;
        int len1,len2;
        len1= len2 = 0;
        while(p1){ //get the list length
            len1++;
            p1 = p1->next;
        }
        while(p2){
            len2++;
            p2 = p2->next;
        } 
        
        p1 = headA;
        p2 = headB;
        if(len2 > len1){ //move the poiter of the longer one forward len2 - len1
            while(len2 > len1){
                p2 = p2->next;
                len2--;
            }
        }else{
            while(len1 > len2){
                p1= p1->next;
                len1--;
            }
        }
        while(p1 && p2){ //move forward at the same time and find if two pt has the same address
            if(p1 != p2){
                p1 = p1->next;
                p2 = p2->next;
            }else{
                return p1;
            }
            
        }
        return NULL;
    }