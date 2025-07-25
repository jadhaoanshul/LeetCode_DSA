class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> m;
        long long s = 0, e = 0, sm = 0;

        // Initialize the first window
        while (e < k) m[nums[e]]++, sm += nums[e++];
        if (m.size() == k) ans = sm;

        // Slide the window
        while (e < nums.size()) {
            sm = sm + nums[e] - nums[s];
            m[nums[s]]--;
            if (m[nums[s]] == 0) m.erase(nums[s]);
            m[nums[e]]++;
            if (m.size() == k) ans = max(ans, sm);
            e++, s++;
        }
        return ans;
    }
};