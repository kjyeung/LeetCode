class MapSum {
public:
    class Trie{
    public:
        int val;
        Trie *next[26];
        Trie(){
            val = 0;
            memset(next, 0, sizeof(next));
        }
    };
    Trie* root;
    unordered_map<string, int> table;
    
    MapSum() {
        root = new Trie();
        table.clear();
    }
    
    void insert(string key, int val) {
        int delta = val;
        if(table.count(key)) delta -= table[key];
        Trie* t = root;
        for(char c : key){
            c -= 'a';
            if(t->next[c] == nullptr) t->next[c] = new Trie();
            t = t->next[c];
            t->val += delta;
        }
        table[key] = val;
        return;
    }
    
    int sum(string prefix) {
        Trie* t = root;
        for(char c : prefix){
            c-='a';
            if(t->next[c] == nullptr) return 0;
            t = t->next[c];
        }
        return t->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */