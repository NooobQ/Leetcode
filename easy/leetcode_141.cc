//141.linked-list-cycle
//tag:fast-slow-pointer
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
    bool hasCycle(ListNode *head) {
        ListNode* fast=head,*slow=head;
        while(fast&&head){
            fast=fast->next;
            if(fast)
                fast=fast->next;
            else
                return false;
            slow=slow->next;
            if(fast==slow)
                return true;
        }
        return false;
    }
};
