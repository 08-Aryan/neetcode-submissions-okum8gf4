/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        Node * curr = head;
        // Copying all nodes and integrating it with linked list
        while(curr){
            Node *temp = new Node(curr->val);
            Node *next = curr->next;
            curr->next = temp;
            temp->next = next;
            curr = next;
        }

        // making the desired linked list
        curr = head;
        while(curr){
  
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        Node * original = head;
        Node * newHead = head->next;
        Node * clone = newHead;
        while(original){
            original->next = original->next->next;
            if(clone->next){
                clone->next = clone->next->next;
            }
            original = original->next;
            clone = clone->next;
        }
        return newHead;


    }
};
