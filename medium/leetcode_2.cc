/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1=l1,*cur2=l2;
        bool flag=false;
        while(cur1&&cur2){
            cur1->val+=cur2->val+flag;
            if(cur1->val>=10){
                cur1->val-=10;
                flag=true;
            }
            else
                flag=false;
            cur1=cur1->next,cur2=cur2->next;
        }
        if(cur1){
            while(cur1){
                int tmp=(cur1->val+flag)%10;
                flag=(cur1->val+flag>=10);
                cur1->val=tmp;
                if(cur1->next==nullptr&&flag){
                    cur1->next=new ListNode(1);
                    break;
                }
                cur1=cur1->next;
            }
            return l1;
        }
        else{
            cur1=l1;
            while(cur1->next)
                cur1=cur1->next;
            while(cur2){
                int tmp=(cur2->val+flag)%10;
                flag=(cur2->val+flag>=10);
                cur1->next=new ListNode(tmp);
                cur1=cur1->next;
                cur2=cur2->next;
            }
        }
        if(flag)
            cur1->next=new ListNode(1);
        return l1;
    }
};


class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1=l1,*cur2=l2,*pre;
        bool flag=false;
        while(cur1&&cur2){
            int tmp=cur1->val+cur2->val+flag;
            flag=tmp/10;
            cur1->val=tmp%10;
            pre=cur1;
            cur1=cur1->next,cur2=cur2->next;
        }
        if(cur2)
            cur1=cur2;
        while(cur1){
            int tmp=(cur1->val+flag)%10;
            flag=(cur1->val+flag)/10;
            pre->next=new ListNode(tmp);
            cur1=cur1->next;
            pre=pre->next;
        }
        if(flag)
            pre->next=new ListNode(1);
        return l1;
    }
};
