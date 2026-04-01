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
typedef pair<ListNode*,int> pli;
struct comp{
    bool operator()(pli &a,pli &b){
        return (a.first)->val > (b.first)->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        priority_queue<pli,vector<pli>,comp> pq;
        int n = lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]){
                pq.push({lists[i],i});
                lists[i] = lists[i]->next;
            }
        }
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            auto node = top.first;
            curr->next = node;
            curr = curr->next;
            int id = top.second;
            if(lists[id]){
                pq.push({lists[id],id});
                lists[id]=lists[id]->next;
            }
        }
        return dummy->next;
        
    }
};
