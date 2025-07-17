class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;
        vector<pair<char, int>> freq(mp.begin(), mp.end());
        sort(freq.begin(), freq.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        string t = "";
        for (auto &p : freq) {
            t += string(p.second, p.first);  // repeat character by its frequency
        }

        return t;
    }
};
