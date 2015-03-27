    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA), lenB = getLength(headB);
        int diff = abs(lenA - lenB);
        if (lenA > lenB) {
            while (diff--) {
                headA = headA->next;
            }
        } else {
            while (diff--){
                headB = headB->next;
            }
        }
        while (headA && headB) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    int getLength(ListNode *node){
        if (node == NULL) return 0;
        int count = 0;
        while (node != NULL) {
            node = node->next;
            count++;
        }
        return count;
    }