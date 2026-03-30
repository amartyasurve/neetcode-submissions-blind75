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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* deciderPtr=new ListNode(-1);
        ListNode* newHead=deciderPtr;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val)
            {
                deciderPtr->next=list1;
                deciderPtr=list1;
                list1=list1->next;
            }
            else {
                deciderPtr->next=list2;
                deciderPtr=list2;
                list2=list2->next;
            }
        }

        if(list1!=nullptr){
            deciderPtr->next=list1;
             
        }
        if(list2!=nullptr){
            deciderPtr->next=list2;
        }
        return newHead->next;
    }
};
