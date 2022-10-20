class Trie{
public:
    bool isEnd;
    string w;
    Trie* next[26];
    Trie(){
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    void insert(string word){
        Trie* node = this;
        for(char c : word){
            c -='a';
            if(node->next[c] == nullptr) node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isEnd = true;
        node->w = word;
    }
    
    string replace(string word){
        Trie* node = this;
        for(char c : word){
            c -= 'a';
            if(node->isEnd) return node->w;
            if(node->next[c] == nullptr) return word;
            node  = node->next[c];
        }
        return word;
        
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream input(sentence);
        string tmp;
        Trie* t = new Trie();
        for(string word : dictionary){
            t->insert(word);
        }
        
        string res;
        while(input >> tmp){
            res += t->replace(tmp) + ' ';
        }
        res.pop_back();
        return res;
    }
};