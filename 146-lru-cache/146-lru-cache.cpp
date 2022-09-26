class LRUCache {
    struct Node{
        int k, v;
        Node *prev, *next;
        Node(int _k, int _v): k(_k), v(_v), prev(nullptr), next(nullptr) {};
    };
    Node *L, *R;
    int n;
    unordered_map<int, Node*> hash;
public:
    void remove(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    
    void insert(Node* node){
        L->next->prev = node;
        node->next = L->next;
        L->next = node;
        node->prev = L;
    }
    
    LRUCache(int capacity) {
        n = capacity;
        L = new Node(-1, -1);
        R = new Node(-1, -1);
        L->next = R;
        R->prev = L;
        hash.clear();
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end()) return -1;
        Node* node = hash[key];
        remove(node);
        insert(node);
        return node->v;
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end()){
            Node* node = hash[key];
            node->v = value;
            remove(node);
            insert(node);
        }else{
            if(hash.size() == n){
                Node* cur = R->prev;
                hash.erase(cur->k);
                remove(cur);
                delete cur;
            }
            Node* node = new Node(key, value);
            hash[key] = node;
            insert(node);
        }
        return;
    }
};