class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        std::array<char, 101> freq; // std::unordered_map<int, char> freq;
        std::vector<int> ret;

        for (const int num: nums1) {
            freq[num] |= 1;
        }

        for (const int num: nums2) {
            auto& find = freq[num];
            if (find == 1) {
                ret.push_back(num);
            }
            find |= 2;
        }
    
        for (const int num: nums3) {
            auto& find = freq[num];

            if (find == 1 || find == 2) {
                ret.push_back(num);
            }
            find |= 4;
        }

        return ret;
    }
};