class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = word.find(ch); // Find the first occurrence of ch
        if (idx == string::npos) return word; // If ch not found, return word as is

        reverse(word.begin(), word.begin() + idx + 1); // Reverse prefix
        return word;
    }
};
