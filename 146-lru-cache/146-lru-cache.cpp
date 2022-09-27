class LRUCache {
public:
    struct Node{
        int key, val;
        Node* prev, *next;
        Node(int _k, int _v): key(_k), val(_v), prev(nullptr), next(nullptr){}
    } *L, *R;
    
    int cap;
    unordered_map<int, Node*> table;
    
    void remove(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    
    void insert(Node* node){
        node->next = L->next;
        L->next->prev = node;
        L->next = node;
        node->prev = L;
    }
    
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        cap = capacity;
        L = new Node(-1, -1);
        R = new Node(-1,-1);
        L->next = R;
        R->prev = L;
        table.clear();
    }
    
    
    int get(int key) {
        if(!table.count(key)) return -1;
        Node* node = table[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(!table.count(key)){
            if(table.size() == cap){
                Node* lru = R->prev;
                table.erase(lru->key);
                remove(lru);
                delete lru;
            }
            Node* cur = new Node(key, value);
            table[key] = cur;
            insert(cur);
            
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