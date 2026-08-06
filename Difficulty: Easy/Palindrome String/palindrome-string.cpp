class Solution {
private:
    bool checkPalindrome(string &s, int start, int end) {
        if (start >= end) {
            return true;
        }
        if (s[start] != s[end]) {
            return false;
        }
        return checkPalindrome(s, start + 1, end - 1);
    }
public:
    bool isPalindrome(string &s) {
        return checkPalindrome(s, 0, s.size() - 1);
    }
};