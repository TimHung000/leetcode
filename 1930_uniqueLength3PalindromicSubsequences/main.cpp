#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        
        std::unordered_map<int,int> right(26);
        std::unordered_set<int> left;
        std::unordered_set<std::string> res;
        for(int i=0;i<s.size();i++)
          right[s[i]-'a']++;
       
        for(int i = 0; i < s.size(); ++i){
            --right[s[i]-'a'];
            if(right[s[i]-'a'] == 0)
                right.erase(s[i]-'a');
            
            if(left.size() > 0){
                for(auto it:left){
                    std::string temp="";
                    if(right.find(it) != right.end()){
                        temp += it;
                        temp += s[i];
                        temp += it;
                        res.insert(temp);
                    }   
                }   
            }
            left.insert(s[i]-'a');
        }
        
        return res.size();
    }
};