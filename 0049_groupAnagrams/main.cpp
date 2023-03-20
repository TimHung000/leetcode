#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(int i = 0; i < strs.size(); ++i)
        {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            umap[tmp].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(unordered_map<string, vector<string>>::iterator it = umap.begin(); it != umap.end(); ++it)
        {
            res.push_back((*it).second);
        }
        return res;
    }
};