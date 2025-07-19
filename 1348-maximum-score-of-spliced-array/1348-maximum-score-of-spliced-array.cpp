class Solution {
public:
    int n;
    int help(vector<int> & nums,vector<int> &other){
        vector<int> dp(3,0);
        for(int i=n-1;i>=0;i--){
            dp[0]=max(nums[i]+dp[0],other[i]+dp[1]);
            dp[1]=max(other[i]+dp[1],nums[i]+dp[2]);
            dp[2]=nums[i]+dp[2];
        }
        return max({dp[0],dp[1],dp[2]});
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        return max(help(nums1,nums2),help(nums2,nums1));
        
    }
};