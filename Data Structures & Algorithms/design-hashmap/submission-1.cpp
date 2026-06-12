class ListNode{
public:
    int key, val;
    ListNode * next;
    ListNode(int key,int value){
        this->key = key;
        this->val = value;
        this->next = nullptr;
    }
};
class MyHashMap {
    vector<ListNode*> mpp;
    int hash(int key){
        return key % mpp.size();
    }
public:
    MyHashMap() {
        mpp.resize(1000);
        for(auto &bucket:mpp){
            bucket = new ListNode(0,0);
        }
    }
    
    void put(int key, int value) {
        ListNode * curr = mpp[hash(key)];
        while(curr->next){
            if(curr->next->key==key){
                curr->next->val = value;
                return;
            }
            curr = curr->next;
        }
        curr->next = new ListNode(key,value);
    }
    
    int get(int key) {
        ListNode *curr = mpp[hash(key)];
        while(curr->next){
            if(curr->next->key==key){
                return curr->next->val;
            }
            curr=curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode *curr = mpp[hash(key)];
        while(curr->next){
            if(curr->next->key==key){
                ListNode * temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr=curr->next;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */