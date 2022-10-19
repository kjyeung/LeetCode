class Trie{
public:
    int sum;
    Trie* next[26];
    
    Trie(){
        sum = 0;
        memset(next, 0, sizeof(next));
    }
    
    void insert(string key, int val){
        Trie* node = this;
        for(char c : key){
            c -= 'a';
            if(node->next[c] == nullptr) node->next[c] = new Trie();
            node = node->next[c];
            node->sum += val;
        }
        return;
    }
    
    int search(string prefix){
        Trie* node = this;
        for(char c : prefix){
            c -= 'a';
            if(node->next[c] == nullptr) return 0;
            node = node->next[c];
        }
        return node->sum;
        
    }
};
class MapSum {
public:
    unordered_map<string ,int> table;
    Trie* t = nullptr;
    MapSum() {
        table.clear();
        t = new Trie();
    }
    
    void insert(string key, int val) {
        int delta = val;
        if(table.find(key) != table.end()) delta -= table[key];
        table[key] = val;
        t->insert(key, delta);
    }
    
    int sum(string prefix) {
        return t->search(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */