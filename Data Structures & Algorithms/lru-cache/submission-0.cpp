class node{
    public:
    int key;
    int val;
    node *next;
    node *prev;
    

        node(int key,int val){
            this->val=val;
            this->key=key;
            next = NULL;
            prev = NULL;
        }
} ;
class LRUCache{
    int size;
    int capacity;
    unordered_map<int,node*> Cache;
    node *head;node *tail;
    void deleteCache(node * element){
            element->next->prev = element->prev;
            element->prev->next = element->next;
            size--;
            
    }
    void insertCache(node * element){
        element->next = head->next;
        element->prev = head;
        head->next->prev = element;
        head->next = element;
        size++;
    }
    public:
        LRUCache(int capacity){
            size = 0;
            this->capacity = capacity;
                   head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
        }
        int get(int key){
            if(Cache.find(key) != Cache.end()){
                deleteCache(Cache[key]);
                insertCache(Cache[key]);
                return Cache[key]->val;
            }
            return -1;
        }

        void put(int key,int value){
            if(Cache.find(key)!= Cache.end()){
node* n = Cache[key];
deleteCache(n);
Cache.erase(key);
delete n;
            }
            node * newCache = new node(key,value);
            Cache[key]=newCache;
            insertCache(newCache);
            if(size > capacity){
                
                node* prev = tail->prev;
                Cache.erase(prev->key);
                deleteCache(prev);
                delete(prev);

                
            }

            
            
        }
};
