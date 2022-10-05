class Trie{
public:
    Trie* next[26];
    bool isEnd;
    Trie(){
        memset(next, 0, sizeof(next));
        isEnd = false;
    }
    
    void insert(const string & word){
        Trie* node = this;
        for(char c : word){
            c -= 'a';
            if(node->next[c] == nullptr) node->next[c] = new Trie();
            node= node->next[c];
        }
        node->isEnd = true;
        return;
    }
    
    bool search(const string & word, int x){
        Trie* node = this;
        if(x == word.size()) return node->isEnd;
        if(word[x] == '.'){
            bool found = false;
            for(int i = 0; i < 26; i++){
                Trie* child = node->next[i];
                if(child && child->search(word, x + 1)) found = true;
            }
            return found;
        }else{
            Trie* child  = node->next[word[x] - 'a'];
            if(child) return child->search(word, x + 1);
            
        }
        return false;
    }
    
};
class WordDictionary {
public:
    Trie* t;
    WordDictionary() {
        t = new Trie();
    }
    
    void addWord(string word) {
        t->insert(word);
        return;
    }
    
    bool search(string word) {
        return t->search(word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */