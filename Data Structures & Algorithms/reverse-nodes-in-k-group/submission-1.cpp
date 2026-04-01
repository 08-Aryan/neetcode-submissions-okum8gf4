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
/* 
*Two Pointer at start one move once other 2 places 2 start from next of start
* If second pointer is ended before counter reaches K then just reverse first part
and connect last
else reverse both and return final linked list
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode * curr = head;
        ListNode * prev = NULL;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head){
            return NULL;
        }
        ListNode * tail = head;
        int count = 1;
        while(count < k && tail){
            tail = tail->next;
            count++;
        }
        if(!tail){
            return head;
        }
        ListNode* next = tail->next;
        tail->next = NULL;
        ListNode * connectingHead = reverseKGroup(next,k);
        
        ListNode * newHead = reverseList(head);
        head->next = connectingHead;
        return newHead;
        
    }
};
