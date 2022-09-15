struct Trie{
    int num;
    Trie* next[26];
    Trie(){
        num = 0;
        memset(next, 0, sizeof(next));
    }
};
class MapSum {
private:
    Trie* root;
    unordered_map<string, int> table;
public:
    MapSum() {
        root = new Trie();
    }
    
    void insert(string key, int val) {
        Trie* t = root;
        int delta = val;
        if(table.count(key)) delta -= table[key];
        table[key] = val;
        
        for(char c : key){
            c -= 'a';
            if(t->next[c] == nullptr) t->next[c] = new Trie();
            t = t->next[c];
            t->num += delta;
        }
        return;
        
    }
    
    int sum(string prefix) {
        Trie* t = root;
        for(char c : prefix){
            c -= 'a';
            if(t->next[c] == nullptr) return 0;
            t = t->next[c];
        }
        return t->num;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */