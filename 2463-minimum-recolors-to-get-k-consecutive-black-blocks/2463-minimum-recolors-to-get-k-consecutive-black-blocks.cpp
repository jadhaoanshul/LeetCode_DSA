class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minWhite = INT_MAX;
        int white = 0;
        int n = blocks.size();

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') white++;
        }

        minWhite = white;

        for (int i = k; i < n; i++) {
            if (blocks[i - k] == 'W') white--;
            if (blocks[i] == 'W') white++;
            minWhite = min(minWhite, white);
        }

        return minWhite;
    }
};
