struct Node{
    int key, val;
    Node* prev, *next;
    Node(int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr){}
};
class LRUCache {
    Node* L, *R;
    int cap;
    unordered_map<int,Node*> table;
public:
    void remove(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
        return;
    }
    
    void insert(Node* node){
        L->next->prev = node;
        node->next = L->next;
        L->next = node;
        node->prev = L;
        return;
    }
    
    LRUCache(int capacity) {
        L = new Node(-1, -1);
        R = new Node(-1, -1);
        L->next = R;
        R->prev = L;
        cap = capacity;
        table.clear();
    }
    
    
    int get(int key) {
        if(!table.count(key)) return -1;
        Node* cur = table[key];
        remove(cur);
        insert(cur);
        return cur->val;
    }
    
    void put(int key, int value) {
        if(table.count(key)){
            Node* cur = table[key];
            cur->val = value;
            remove(cur);
            insert(cur);
        }else{
            if(table.size() == cap){
                Node* lru = R->prev;
                table.erase(lru->key);
                remove(lru);
                delete lru;
            }
            
            Node* cur = new Node(key, value);
            table[key] = cur;
            insert(cur);
        }
        
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */