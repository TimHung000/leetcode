#include <string>

class Solution {
private:
    bool isPalindrome(std::string &s){
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void dfs(int idx, std::string &s1, std::string &s2, std::string& s, int &res){
        if(idx >= s.length()) {
            if(isPalindrome(s1) && isPalindrome(s2)){
                int len = s1.length() * s2.length();
                res = std::max(res, len);
            }
            return;
        }
        
        char c = s[idx];

        // add the character in the first string
        s1.push_back(c);
        dfs(idx + 1, s1, s2, s, res);
        s1.pop_back();

        // add the character in the second string
        s2.push_back(c);
        dfs(idx + 1, s1, s2, s, res);
        s2.pop_back();

        // add character in no string
        dfs(idx + 1, s1, s2, s, res);
    }
public:
    int maxProduct(std::string s) {

        std::string s1 = "";
        std::string s2 = "";
        int idx = 0;
        int res = 0;
        dfs(idx, s1, s2, s, res);

        return res;
    }
};