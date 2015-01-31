 struct comparator{

        bool operator() (ListNode *a, ListNode *b){
            return a->val > b->val;
        }     
 }comp;
class Solution {
public:

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int size = lists.size();
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        priority_queue<ListNode*, vector<ListNode*>, comparator> q; //priority_queue requires class/struct name rather than object
        
        for(int i = 0; i < size; i++){
            if(lists[i]){
                q.push(lists[i]);
            }
        }
        
        while(!q.empty()){
            cur->next = q.top();
            cur = cur->next;
            q.pop();
            if(cur->next) q.push(cur->next);
            cur->next = NULL;
        }
        
        return dummy->next;
    }
};

//divide and conquer
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()) return NULL;
        
        while(lists.size() > 1){
            ListNode *tmp = mergeTwoList(lists[0],lists[1]);
            lists.push_back(tmp);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        
        
        return lists[0];
    }
    ListNode *mergeTwoList(ListNode* a, ListNode* b){

        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        
        while(a && b){
            if(a->val > b->val){
                cur->next = b;
                b = b->next;
            } else{
                cur->next = a;
                a = a->next;
            }
            cur = cur->next;
        }
        if(a) cur->next = a;
        else cur->next = b;
        
        return dummy->next;
    }
