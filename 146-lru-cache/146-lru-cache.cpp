struct Node{
    int key, val;
    Node* next, *prev;
    Node(int _key, int _val): key(_key), val(_val){}
};
class LRUCache {
private:
    Node* L, *R;
    int cap;
    unordered_map<int,Node*> table;
public:
    void remove(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    
    void insert(Node* node){
        L->next->prev = node;
        node->next = L->next;
        node->prev = L;
        L->next = node;
    }
    
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
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
        int ret = cur->val;
        remove(cur);
        insert(cur);
        return ret;
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
            Node* node = new Node(key, value);
            insert(node);
            table[key] = node;
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