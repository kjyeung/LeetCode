class Trie{
public:
    bool isEnd;
    Trie* next[26];
    Trie(){
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    void insert(const string & word){
        Trie* node = this;
        for(char c : word){
            c -= 'a';
            if(node->next[c] == nullptr) node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isEnd = true;
        return;
    }
    bool search(const string& word, int idx){
        if(idx == word.size()) return this->isEnd;
        Trie* node = this;
        char c = word[idx];
        if(c != '.'){
            Trie* child = node->next[c-'a'];
            return child && child->search(word, idx + 1);
        }else{
            for(int i = 0; i < 26 ; i++){
                Trie* child = node->next[i];
                if(child && child->search(word,idx + 1))  return true;
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