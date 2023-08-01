#include <string>

using namespace std;


class Trie {
private:
    Trie *next[26];
    bool isWord;

public:
    Trie(): next(),isWord(false) {
    }
    
    void insert(string word) {
        Trie *node = this;
        for(int i = 0; i < word.length(); ++i)
        {
            if(!node->next[word[i]-'a']) node->next[word[i]-'a'] = new Trie();
            node = node->next[word[i]-'a'];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        Trie *node = this;
        for(int i = 0; i < word.length(); ++i)
        {
            if(!node->next[word[i]-'a']) return false;
            node = node->next[word[i]-'a'];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie *node = this;
        for(int i = 0; i < prefix.length(); ++i)
        {
            if(!node->next[prefix[i]-'a']) return false;
            node = node->next[prefix[i]-'a'];
        }
        return true;        
    }
};