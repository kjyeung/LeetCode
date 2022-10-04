class Trie{
public:
    Trie* next[26];
    bool isEnd;
    string word;
    Trie(){
        isEnd = false;
        memset(next, 0, sizeof(next));
        word = "";
    }
    
    void insert(string word){
        Trie* node = this;
        for(char c : word){
            c -= 'a';
            if(node->next[c] == nullptr) node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isEnd = true;
        node->word = word;
    }
    
    string replace(string word){
        Trie* node = this;
        for(char c : word){
            c -= 'a';
            if(node->isEnd) return node->word;
            if(node->next[c] == nullptr) return word;
            node = node->next[c];
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* t = new Trie();
        for(string& word : dictionary){
            t->insert(word);
        }
        
        stringstream input(sentence);
        string tmp;
        string res;
        while(input >> tmp){
            res += t->replace(tmp) + " ";
        }
        res.pop_back();
        return res;
    }
};