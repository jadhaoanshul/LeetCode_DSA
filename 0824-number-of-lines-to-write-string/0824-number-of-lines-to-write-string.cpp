class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int maxWidth = 100;
        int lines = 1; // Start with one line
        int currentWidth = 0;
        
        for (char c : s) {
            int width = widths[c - 'a']; // Map 'a'-'z' to 0-25
            if (currentWidth + width > maxWidth) {
                lines++;
                currentWidth = width;
            } else {
                currentWidth += width;
            }
        }

        return {lines, currentWidth};
    }
};
