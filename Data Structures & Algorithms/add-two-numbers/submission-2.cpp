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
        ListNode * dummy = new ListNode();
        ListNode *tail = dummy;
        int carry = 0;
        while((l1 || l2 || carry)){
            int v1 = (l1)? l1->val : 0;
            int v2 = (l2)? l2->val : 0;
            int calc = v1+v2+carry;
            int val = calc%10; 
            carry = calc/10; 

            ListNode* sum = new ListNode(val);
            tail->next = sum;
            tail = tail->next;
            l1=(l1) ? l1->next :NULL;
            l2=(l2) ? l2->next :NULL;
            
        }

        return dummy->next;
    }
};
