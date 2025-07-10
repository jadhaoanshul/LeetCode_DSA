class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            map<char, int> hash;  // Reset hash map for each new i
            for (int j = i; j < n; j++) {
                if (hash[s[j]] == 1)
                    break;
                hash[s[j]] = 1;
                int len = j - i + 1;
                maxlen = max(maxlen, len);
            }
        }

        return maxlen;
    }
};
