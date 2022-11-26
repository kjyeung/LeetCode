class Trie {
private:
    Trie* next[26];
    bool isEnd;
public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char c : word){
            c -= 'a';
            if(node->next[c] == nullptr) node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isEnd = true;
        return;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c : word){
            c -= 'a';
            if(node->next[c] == nullptr) return false;
            node = node->next[c];
        }
        return node->isEnd;
        
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c : prefix){
            c -= 'a';
            if(node->next[c] == nullptr) return false;
            node = node->next[c];
        }
        if(node->isEnd) return true;
        for(int i = 0; i < 26; i++){
            if(node->next[i]) return true;
        }
        return false;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */