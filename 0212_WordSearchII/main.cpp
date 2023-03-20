#include <vector>
#include <string>

using namespace std;

class TrieNode {
private:
    TrieNode *next[26];
    bool isWord;
public:
    TrieNode(): next(), isWord(false) {}
    ~TrieNode()
    {
        delete[] next;
    }
    friend class Trie;
    friend class Solution;
};

class Trie {
private:
    TrieNode *root;

public:
    Trie() 
    {
        root = new TrieNode();
    }
    ~Trie()
    {
        delete root;
    }
    void addNode(string word)
    {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(!node->next[word[i]-'a'])
                node->next[word[i]-'a'] = new TrieNode();
            
            node = node->next[word[i]-'a'];
        }
        node->isWord = true;
    }
    friend class Solution;
};



class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* myTrie = new Trie();
        vector<string> res;
        for(int i = 0; i < words.size(); ++i)
            myTrie->addNode(words[i]);

        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[i].size(); ++j)
            {
                string tempWord;
                helper(res, board, i, j, myTrie->root, tempWord);
            }
        }
        return res;
    }
private:
    void helper(vector<string>& res, vector<vector<char>>& board, int row, int column, TrieNode *node, string& tempWord)
    {
        if(row >= board.size() || row < 0 || column >= board[row].size() || column < 0 || board[row][column] == '*')
            return;
        
        if(node->next[board[row][column]-'a'])
        {
            tempWord.push_back(board[row][column]);
            node = node->next[board[row][column]-'a'];
            if(node->isWord)
                res.push_back(tempWord);

            board[row][column] = '*';
            helper(res, board, row-1, column, node, tempWord);
            helper(res, board, row, column+1, node, tempWord);
            helper(res, board, row+1, column, node, tempWord);
            helper(res, board, row, column-1, node, tempWord);
            board[row][column] = tempWord[tempWord.size()-1];
            tempWord.pop_back();
        }
    }
    
};