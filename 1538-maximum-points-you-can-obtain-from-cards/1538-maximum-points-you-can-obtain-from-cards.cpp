class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0, maxsum = 0;
        int n = cardPoints.size();

        // Take first k elements from the left
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        maxsum = lsum;

        // Now remove from left and add from right
        for (int i = 0; i < k; i++) {
            lsum -= cardPoints[k - 1 - i];
            rsum += cardPoints[n - 1 - i];
            maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};
