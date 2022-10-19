struct Node{
    int key;
    int val;
    Node* prev, *next;
    Node(int _k, int _v):key(_k), val(_v), prev(NULL), next(NULL){}
};
class LRUCache {
private:
    Node* L, *R;
    unordered_map<int ,Node*> table;
    int cap;
    
    void remove(Node* cur){
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        return;
    }
    
    void insert(Node* cur){
        L->next->prev = cur;
        cur->next = L->next;
        cur->prev = L;
        L->next = cur;
        return;
    }
public:
    LRUCache(int capacity) {
        L = new Node(-1, -1);
        R = new Node(-1, -1);
        L->next = R;
        R->prev = L;
        table.clear();
        cap = capacity;
    }
    
    int get(int key) {
        if(table.find(key) == table.end()) return -1;
        Node* cur = table[key];
        remove(cur);
        insert(cur);
        return cur->val;
    }
    
    void put(int key, int value) {
        if(table.find(key) != table.end()){
            Node* cur = table[key];
            cur->val = value;
            remove(cur);
            insert(cur);
        }else{
            if(table.size() == cap){
                Node* lru = R->prev;
                int k = lru->key;
                
                remove(lru);
                table.erase(k);
                delete lru;
            }
            Node* cur = new Node(key, value);
            insert(cur);
            table[key] = cur;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */