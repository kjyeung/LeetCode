struct Node{
    int key, val;
    Node* prev, *next;
    Node(int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr){}
};
class LRUCache {
    Node *L, *R;
    unordered_map<int, Node*> table;
    int cap;
    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = nullptr;
        node->next = nullptr;
        return;
    }
    
    void insert(Node* node){
        node->prev = L;
        node->next = L->next;
        L->next->prev = node;
        L->next = node;
        return;
        
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        
        L = new Node(-1, -1);
        R = new Node(-1, -1);
        L->next = R;
        R->prev = L;
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
        if(!table.count(key)){
            if(table.size() == cap){
                Node* lru = R->prev;
                int lruk = lru->key;
                remove(lru);
                delete lru;
                table.erase(lruk);
            }
            Node* node = new Node(key, value);
            table[key] = node;
            insert(node);
        }else{
            Node* node = table[key];
            node->val = value;
            remove(node);
            insert(node);
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