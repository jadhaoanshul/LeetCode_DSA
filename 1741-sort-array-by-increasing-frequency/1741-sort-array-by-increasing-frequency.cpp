class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int c : nums) mp[c]++;
        vector<pair<int, int>> freq(mp.begin(), mp.end());
        sort(freq.begin(), freq.end(), [](auto &a, auto &b) {
            if (a.second == b.second)
                return a.first > b.first;  // ascending by value
            return a.second < b.second;   // descending by frequency
        });

        vector<int> result;
        for (auto &p : freq) {
            for (int i = 0; i < p.second; i++) {
                result.push_back(p.first);
            }
        }

        return result;
    }
};