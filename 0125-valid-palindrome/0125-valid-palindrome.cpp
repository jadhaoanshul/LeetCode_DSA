class Solution {
public:
    bool pali(int i, string &s) {
        if (i >= s.length() / 2) return true;
        if (s[i] != s[s.length() - i - 1]) return false;
        return pali(i + 1, s);
    }

    bool isPalindrome(string s) {
        string filtered = "";
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }
        return pali(0, filtered);
    }
};
