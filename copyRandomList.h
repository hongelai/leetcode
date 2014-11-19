//难点在于random pointer的复制，可能指向未来的节点，所以要先把链表复制 然后赋值random pointer。
//但是两个链表的的同一个节点的random pointer指向的地址是不同的，所以要在原来的链表上插入构造新的链表
    RandomListNode *copyRandomList(RandomListNode *head) {
        for(RandomListNode * cur = head; cur != nullptr;){
            int data = cur->label;
            RandomListNode *newNode = new RandomListNode(data);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = cur->next->next;
        }
        for(RandomListNode* cur = head; cur != nullptr;){
        	if (cur->random)
        		cur->next->random = cur->random->next;	
        	cur = cur->next->next;
        }
        //seperate two list
        RandomListNode* dummy = new RandomListNode(-1);
        for (RandomListNode* cur = head, *new_cur = dummy; cur != nullptr;)
        {
        	new_cur->next = cur->next;
        	new_cur = new_cur->next;
        	cur->next = cur->next->next;
        	cur = cur->next;
        }
        return dummy->next;
    }