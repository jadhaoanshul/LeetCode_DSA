class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; // stores frequency
        int left = 0, right = 0;
        int currentSum = 0, maxSum = 0;

        while (right < n) {
            mp[nums[right]]++;
            currentSum += nums[right];

            while (mp[nums[right]] > 1) {
                mp[nums[left]]--;
                currentSum -= nums[left];
                left++;
            }

            maxSum = max(maxSum, currentSum);
            right++;
        }

        return maxSum;
    }
};
