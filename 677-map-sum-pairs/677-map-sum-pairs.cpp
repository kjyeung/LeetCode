class Trie{
public:
    int val;
    Trie* next[26];
    Trie(){
        val = 0;
        memset(next, 0, sizeof(next));
    }
};
class MapSum {
public:
    unordered_map<string, int> table;
    Trie* root;
    MapSum() {
        root = new Trie();
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    }
    
    void insert(string key, int val) {
        Trie* t = root;
        int delta = val;
        if(table.count(key)){
            delta -= table[key];
        }
        table[key] = val;
        
        for(char c : key){
            c -= 'a';
            if(t->next[c]== nullptr) t->next[c] = new Trie();
            t = t->next[c];
            t->val += delta;
        }
    }
    
    int sum(string prefix) {
        Trie* t = root;
        for(char c : prefix){
            c -= 'a';
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