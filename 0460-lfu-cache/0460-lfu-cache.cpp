struct Node{
    int key, val, freq;
    Node(int _k, int _v, int _f): key(_k), val(_v), freq(_f){}
};
class LFUCache {
private:
    int minf, cap;
    unordered_map<int, list<Node>::iterator> keytable;
    unordered_map<int, list<Node>> freqtable;
    
public:
    LFUCache(int capacity) {
        cap = capacity;
        minf = 0;
        keytable.clear();
        freqtable.clear();
    }
    
    int get(int key) {
        if(cap == 0 || keytable.find(key) == keytable.end()) return -1;
        auto it = keytable[key];
        int v = it->val, f = it->freq;
        
        freqtable[f].erase(it);
        if(freqtable[f].empty()){
            freqtable.erase(f);
            if(f == minf) ++minf;
        }
        
        freqtable[f+1].push_front(Node(key, v, f + 1));
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
            return;
        }
        if(keytable.size() == cap){
            Node lfu = freqtable[minf].back();
            int lfu_k = lfu.key;
            
            freqtable[minf].pop_back();
            if(freqtable[minf].empty()){
                freqtable.erase(minf);
                ++minf;
            }
            
            keytable.erase(lfu_k);
        }
        
        minf = 1;
        freqtable[1].push_front(Node(key, value, 1));
        keytable[key] = freqtable[1].begin();
        return;
        
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */