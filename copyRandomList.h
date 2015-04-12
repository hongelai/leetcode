//难点在于random pointer的复制，可能指向未来的节点，所以要先把链表复制 然后赋值random pointer。
//但是两个链表的的同一个节点的random pointer指向的地址是不同的，所以要在原来的链表上插入构造新的链表
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        
        for(RandomListNode* cur = head; cur != NULL; cur = cur->next->next){
            RandomListNode* newNode = new RandomListNode(cur->label);
            newNode->next = cur->next;
            cur->next = newNode;
        }
        
        for(RandomListNode* cur = head; cur != NULL; cur = cur->next->next){
            if(cur->random) cur->next->random = cur->random->next;
        }
        //seperate two list
        RandomListNode* dummy = new RandomListNode(-1);
        for(RandomListNode* cur = head, *newList = dummy; cur != NULL; cur = cur->next){
            newList->next = cur->next;
            cur->next = cur->next->next;
            newList = newList->next;
        }
        return dummy->next;
    }