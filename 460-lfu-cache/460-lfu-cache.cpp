struct Node{
    int key, val,freq;
    Node(int _key, int _val, int _freq):key(_key), val(_val), freq(_freq){}
};
class LFUCache {
public:
    unordered_map<int, list<Node>> freqtable;
    unordered_map<int, list<Node>::iterator> keytable;
    int minf;
    int cap;
    
    LFUCache(int capacity) {
        freqtable.clear();
        keytable.clear();
        minf = 0;
        cap = capacity;
    }
    
    int get(int key) {
        if(cap == 0 || !keytable.count(key)) return -1;
        auto it = keytable[key];
        int v = it->val, f = it->freq;
        
        freqtable[f].erase(it);
        
        if(freqtable[f].empty()){
            freqtable.erase(f);
            if(f == minf) ++minf;
        }
        
        freqtable[f + 1].push_front(Node(key, v, f + 1));
        keytable[key] = freqtable[f + 1].begin();
        
        return v;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(keytable.count(key)){
            auto it = keytable[key];
            int f = it->freq;
            
            freqtable[f].erase(it);
            
            if(freqtable[f].empty()){
                freqtable.erase(f);
                if(f == minf) ++minf;
            }
            freqtable[f + 1].push_front(Node(key, value, f + 1));
            keytable[key] = freqtable[f + 1].begin();
        }else{
            if(keytable.size() == cap){
                Node lru = freqtable[minf].back();
                int k = lru.key;
                keytable.erase(k);
                freqtable[minf].pop_back();
                
                if(freqtable[minf].empty()){
                    freqtable.erase(minf);
                    ++minf;
                }
            }
            
            freqtable[1].push_front(Node(key,value, 1));
            keytable[key] = freqtable[1].begin();
            minf = 1;
        }
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */