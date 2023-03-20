#include <string>

using namespace std;

class TrieNode {
private:
    TrieNode* next[26];
    bool isWord;
public:
    TrieNode():isWord(false), next() {}
    friend class WordDictionary;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(!node->next[word[i]-'a'])
            {
                node->next[word[i]-'a'] = new TrieNode();
            }
            node = node->next[word[i]-'a'];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return helper(word, 0, root);
    }
private:
    bool helper(string word, int startIndex, TrieNode* node)
    {
        for(int i = startIndex; i < word.size() && node; ++i)
        {
            if(word[i] == '.')
            {
                for(int j = 0; j < 26; j ++)
                {
                    if(helper(word, i+1, node->next[j])) return true;
                }
                return false;

            }
            else
            {
                node = node->next[word[i]-'a'];
            }
        }
        return node && node->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */