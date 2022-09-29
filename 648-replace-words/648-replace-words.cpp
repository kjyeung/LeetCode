class Trie{
private:
    bool isEnd;
    Trie* next[26];
    string word;
public:
    Trie(){
        isEnd = false;
        memset(next, 0 , sizeof(next));
        word = "";
    }
    
    void insert(const string & word){
        Trie* node = this;
        for(char c : word){
            c -= 'a';
            if(node->next[c] == nullptr) node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isEnd = true;
        node->word = word;
    }
    
    string replace(const string & word){
        Trie* node = this;
        for(char c : word){
            c -= 'a';
            if(node->next[c] == nullptr) return word;
            node = node->next[c];
            if(node->isEnd) return node->word;
        }
        return node->isEnd? node->word:word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* t = new Trie();
        for(const string & word : dictionary){
            t->insert(word);
        }
        
        stringstream ss(sentence);
        string res;
        string tmp;
        while(ss>>tmp){
            
            res += t->replace(tmp) + ' ';
        }
        res.pop_back();
        return res;
    }
};