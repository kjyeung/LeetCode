class Node{
public:
    int key, value;
    Node* prev, *next;
    Node(int _k, int _v): key(_k), value(_v), prev(NULL), next(NULL){}
};
class LRUCache {
public:
    unordered_map<int,Node*> table;
    Node *L, *R;
    int cap;
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        cap = capacity;
        table.clear();
        L = new Node(-1, -1);
        R = new Node(-1, -1);
        L->next = R;
        R->prev = L;
    }
    
    void remove(Node* p){
        p->next->prev = p->prev;
        p->prev->next = p->next;
        return;
    }
    void insert(Node* p){
        L->next->prev = p;
        p->next = L->next;
        L->next = p;
        p->prev = L;
        return;
    }
    int get(int key) {
        
        if(!table.count(key)) return -1;
        Node *cur = table[key];
        remove(cur);
        insert(cur);
        return cur->value; 
        
    }
    
    void put(int key, int value) {
        if(table.count(key)){
            Node* cur = table[key];
            cur->value = value;
            remove(cur);
            insert(cur);
        }else{
            if(table.size() == cap){
                Node* lru = R->prev;
                int lruk = lru->key;
                table.erase(lruk);
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