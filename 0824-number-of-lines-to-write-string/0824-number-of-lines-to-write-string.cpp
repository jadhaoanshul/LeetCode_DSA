class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int val = 0, c = 1;  // Start with line 1
        for (int i = 0; i < s.size(); i++) {
            int w = widths[s[i] - 'a'];
            if (val + w > 100) {
                c++;        // move to next line
                val = w;    // start new line with current character
            } else {
                val += w;
            }
        }
        return {c, val};
    }
};
