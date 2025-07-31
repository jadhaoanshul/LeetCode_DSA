class Solution {
public:
    void printS(int ind, vector<int>& sub, vector<int>& nums, vector<vector<int>>& sto){
        if (ind == nums.size()) {
            sto.push_back(sub);
            return;
        }
        sub.push_back(nums[ind]);
        printS(ind+1, sub, nums, sto);
        sub.pop_back();
        printS(ind+1, sub, nums, sto);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sto;
        vector<int> sub;
        int n = nums.size();
        printS(0, sub, nums, sto);
        return sto;
    }
};