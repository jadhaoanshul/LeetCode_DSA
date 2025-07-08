class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int a=0;
        unordered_map<int, int> mp;
        for(int i:nums){
            if(mp[i]) a^=i;
            mp[i]++;
        }
        return a;
    }
};