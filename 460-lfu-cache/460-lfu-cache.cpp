struct Node{
    int f, v, k;
    Node(int _k, int _v, int _f): k(_k), v(_v), f(_f){}
};

class LFUCache {
private:
    int minfreq,cap;
    unordered_map<int, list<Node>> freqtable;
    unordered_map<int, list<Node>::iterator> keytable;
    
public:
    LFUCache(int capacity) {
        minfreq = 0;
        cap = capacity;
        freqtable.clear();
        keytable.clear();
    }
    
    int get(int key) {
        if(cap == 0) return -1;
        if(!keytable.count(key)) return -1;
        auto nodeiter = keytable[key];
        int freq = nodeiter->f, value = nodeiter->v;
        
        freqtable[freq].erase(nodeiter);
        if(freqtable[freq].empty()){
            freqtable.erase(freq);
            if(minfreq == freq) ++minfreq;
        }
        if(!freqtable.count(freq + 1)){
            freqtable[freq + 1] = list<Node>();
        }
        freqtable[freq + 1].push_front(Node(key, value, freq + 1));
        keytable[key] = freqtable[freq + 1].begin();
        return value;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(keytable.count(key)){
            auto nodeiter = keytable[key];
            int freq = nodeiter->f;
            freqtable[freq].erase(nodeiter);
            if(freqtable[freq].empty()){
                freqtable.erase(freq);
                if(minfreq == freq) ++minfreq;
            }
            
            //if(!freqtable.count(freq + 1)){
              //  freqtable[freq + 1] = list<Node>();
            //}
            freqtable[freq + 1].push_front(Node(key, value, freq + 1));
            keytable[key] = freqtable[freq + 1].begin();
        }else{
            if(keytable.size() == cap){
                Node lfu = freqtable[minfreq].back();
                int key = lfu.k, freq = lfu.f;
                keytable.erase(key);
                freqtable[freq].pop_back();
                if(freqtable[freq].empty()){
                    freqtable.erase(freq);
                    if(minfreq == freq) ++minfreq;
                }
                
            }
            minfreq = 1;
            freqtable[1].push_front(Node(key, value, 1));
            keytable[key] = freqtable[1].begin();
            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */