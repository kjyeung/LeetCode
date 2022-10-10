class Trie{
public:
    bool isEnd;
    Trie* next[26];
    
    Trie(){
        isEnd = false;
        memset(next, 0 ,sizeof(next));
    }
    
    void insert(string & word){
        Trie* node = this;
        for(auto & c : word){
            c -= 'a';
            if(node->next[c] == nullptr) node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isEnd = true;
    }
    
    bool search(const string & word, int idx){
        Trie* node = this;
        if(idx == word.size()) return node->isEnd;
        
        if(word[idx] != '.'){
            Trie* child = node->next[word[idx] - 'a'];
            if(child) return child->search(word, idx + 1);
        }else{
            bool found = false;
            for(int i = 0; i < 26; i++){
                Trie* child = node->next[i];
                if(child && child->search(word, idx + 1)){
                    found = true;
                    return found;
                }
            }
            
        }
        return false;
        
    }
    
};
class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        root->insert(word);
    }
    
    bool search(string word) {
        return root->search(word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */