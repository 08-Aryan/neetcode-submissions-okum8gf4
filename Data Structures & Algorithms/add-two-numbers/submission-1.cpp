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
        ListNode * sudo = new ListNode();
        ListNode *tail = sudo;
        int carry = 0;
        while((l1 && l2)){
            int calc = l1->val + l2->val + carry;
            int val = calc%10; 
            carry = calc/10; 
            l1=l1->next;
            l2=l2->next;
            ListNode* sum = new ListNode(val);
            tail->next = sum;
            tail = tail->next;
            
        }
        while(l1){
            int calc = l1->val + carry;
            int val = calc%10; 
            carry = calc/10; 
            l1=l1->next;
            ListNode* sum = new ListNode(val);
            tail->next = sum;
            tail = tail->next;
        }
        while(l2){
            int calc = l2->val + carry;
            int val = calc%10; 
            carry = calc/10; 
            l2=l2->next;
            ListNode* sum = new ListNode(val);
            tail->next = sum;
            tail = tail->next;
        }
        if(carry > 0){
            ListNode* sum = new ListNode(carry);
            tail->next = sum;
        }
        return sudo->next;
    }
};
