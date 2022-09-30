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
            if(node->next[c]== nullptr) node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isEnd= true;
        return;
    }
    
    bool search(const string & word, int x){
        Trie* node = this;
        if(x == word.size() ) return node->isEnd;
        if(word[x] != '.'){
            Trie* child = node->next[word[x] - 'a'];
            if(child && child->search(word, x + 1)) return true;
            else return false;
        }else{
            for(int i = 0; i < 26;i++){
                Trie* child = node->next[i];
                if(child && child->search(word, x + 1)) return true;
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