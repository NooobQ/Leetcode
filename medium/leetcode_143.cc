//143.reorder-list
//tag:linked-list
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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* cur=head;
        while(cur){
            v.push_back(cur);
            cur=cur->next;
        }
        int l=0,r=v.size()-1;
        while(l<r){
           
            v[r]->next=v[l]->next;
            v[l]->next=v[r];
            ++l;--r;
        }
        if(r>=0)
            v[l]->next=NULL;
    }
    void reorderList2(ListNode* head) {
        if(!head)
            return;
        stack<ListNode*> st;
        ListNode *cur=head;
        while(cur!=nullptr){
            st.push(cur);
            cur=cur->next;
        }
        int count=st.size()/2,n=st.size();

        cur=head;
        while(count--){
            ListNode *pnext=nullptr;
            if(cur->next)
                pnext=cur->next;
            cur->next=st.top();
            cout<<cur->val<<"\t   "<<cur->next->val<<endl;
            st.top()->next=pnext;
            st.pop();
            cur=pnext;
        }

        cur=head;
        while(--n){
            cur=cur->next;//tail  pointer->NULL
        }
        cur->next=nullptr;
    }
};
