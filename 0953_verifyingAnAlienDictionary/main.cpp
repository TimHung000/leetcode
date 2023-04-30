// #include <bits\stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> map(26); // 26 characters of lowercase letters
        for(int i = 0; i < order.size(); ++i) {
            map[order[i] - 'a'] = i;
        }
        
        for(int i = 0; i < words.size()-1; ++i) {
            int ptr = 0;
            while(ptr < words[i].size() && ptr < words[i+1].size()) {
                if(map[words[i][ptr]-'a'] < map[words[i+1][ptr]-'a'])
                    break;
                else if(map[words[i][ptr]-'a'] > map[words[i+1][ptr]-'a'])
                    return false;
                else
                    ++ptr;
            }
            if(words[i+1].size() == ptr && words[i].size() > words[i+1].size())
                return false;
        }
        return true;
    }

    bool isAlienSorted1(vector<string> words, string order) {
        int mapping[26];
        for (int i = 0; i < 26; i++)
            mapping[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w)
                c = mapping[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
};


int main() {
    vector<string> test = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    Solution sol;
    sol.isAlienSorted1(test, order);
}