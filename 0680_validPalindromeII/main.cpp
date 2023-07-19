#include <string>

class Solution {
public:
    bool validPalindrome(std::string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) {
                int l1 = l, r1 = r-1, l2 = l+1, r2 = r;
                while(l1 < r1 && s[l1] == s[r1]) {
                    ++l1;
                    --r1;
                }

                while(l2 < r2 && s[l2] == s[r2]) {
                    ++l2;
                    --r2;
                }
                return (l1 >= r1) || (l2 >= r2);
            }
            ++l;
            --r;
        }
        return true;
    }

};

class Solution1 {
private:
    bool ispalindrome(std::string& s, int l, int r){
        while(l < r){
            if(s.at(l) == s.at(r)){
                ++l;
                --r;
            }else 
                return false;
        }
        return true;
    }
public:
    bool validPalindrome(std::string s) {
        int l  = 0;
        int r = s.size()-1;
        while(l < r){
            if(s.at(l) == s.at(r)){
                ++l;
                --r;
            }else
                return ispalindrome(s, l+1, r) || ispalindrome(s, l, r-1);
        }
        return true;
    }
};