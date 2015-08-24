/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* pre, * curr;
        ListNode* FakeNode = new ListNode(0);
        if(head !=  NULL)
            FakeNode->next = head;
        else return head;
        pre = FakeNode;
        curr = head;
        
        while(curr->next != NULL){
            while(curr->next != NULL && curr->val == curr->next->val) curr = curr->next;
            if(curr != pre->next && curr != pre){
                pre->next = curr->next;
                curr = pre;
            }else{
                pre = curr;
                curr = curr->next;
            }
        }
        
        return FakeNode->next;
        
    }
};


    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy, *pre, *pos;
        pre = dummy->next, pos = pre->next;
        
        while(pos){
            while(pos && pos->val == pre->val) pos = pos->next;
            if(pre->next != pos){
                cur->next = pos;
            }else {
                cur = cur->next;
            }
            pre = pos;
            if(pos) pos = pos->next;
        }
        return dummy->next;
    }