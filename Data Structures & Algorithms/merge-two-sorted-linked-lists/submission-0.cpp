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
        ListNode* temp = new ListNode();
        ListNode *curr = temp;
        ListNode* left = list1,*right = list2;
        while(left && right ){
            if(left->val > right->val){
                curr->next = right;
                right = right->next;
            }
            else{
                curr->next = left;
                left = left->next;
            }
            curr = curr->next;
        }
        if(left){
                curr->next = left;
        }
        else if(right){
            curr->next = right;
        }
        return temp->next;

    }
};
