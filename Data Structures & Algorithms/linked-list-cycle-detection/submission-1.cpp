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
    bool hasCycle(ListNode* head) {
        ListNode* fast=new ListNode(-100009);
        ListNode* slow=fast;
        fast->next=head;
        bool isCycle=false;
        while(slow!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr){
            if(fast->val!=-100009 && fast->val==slow->val)return true;
            fast=fast->next->next;
            slow=slow->next;
        }
        return false;
    }
};
