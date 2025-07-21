class Solution {
public:
    void next(vector<int>& v) {
        int pivot = 0;
        int j = -1;

        // Step 1: Find the pivot index
        for (int i = v.size() - 1; i > 0; i--) {
            if (v[i - 1] < v[i]) {
                pivot = v[i - 1];
                j = i - 1;
                break;
            }
        }

        // If no pivot found, reverse to get the first permutation
        if (j == -1) {
            reverse(v.begin(), v.end());
            return;
        }

        // Step 2: Swap with the next greater element from the end
        for (int i = v.size() - 1; i > j; i--) {
            if (v[i] > pivot) {
                swap(v[i], v[j]);
                break;
            }
        }

        // Step 3: Reverse the suffix
        reverse(v.begin() + j + 1, v.end());
    }

    string getPermutation(int n, int k) {
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
        }

        k--;  // As we consider the first permutation as count 1

        while (k--) {
            next(v);
        }

        string ans = "";
        for (auto it : v) {
            ans += it + '0';
        }
        return ans;
    }
}; 