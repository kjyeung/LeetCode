class LRUCache {
public:
    struct Node{
        int key, value;
        Node* left, *right;
        Node(int _key, int _value): key(_key), value(_value), left(NULL), right(NULL){}  
    }*L, *R;;
    int n;
    unordered_map<int, Node*> hash;
    
    void remove(Node* p){
        p->right->left = p->left;
        p->left->right = p->right;
    }
    
    void insert(Node* p){
        p->right = L->right;
        p->left = L;
        L->right->left = p;
        L->right = p;
        
    }
    LRUCache(int capacity) {
        n = capacity;
        L = new Node(-1, -1), R = new Node(-1,-1);
        L->right = R;
        R->left = L;
    }
    
    int get(int key) {
        if(hash.count(key) == 0) return -1;
        auto p = hash[key];
        remove(p);
        insert(p);
        return p->value;
    }
    
    void put(int key, int value) {
        if(hash.count(key)){
            auto p = hash[key];
            p->value = value;
            remove(p);
            insert(p);
        }else{
            if(hash.size() == n){
                auto p = R->left;
                remove(p);
                hash.erase(p->key);
                delete p ;
            }
            auto p = new Node(key, value);
            hash[key] = p;
            insert(p);
        }
    }
};