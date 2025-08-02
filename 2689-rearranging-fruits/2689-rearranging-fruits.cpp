#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();

        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            freq[basket1[i]]++;
            freq[basket2[i]]--;
        }

        vector<int> extra;  // items to be swapped
        for (auto& [num, count] : freq) {
            if (count % 2 != 0) return -1;  // Impossible to match
            for (int i = 0; i < abs(count) / 2; ++i) {
                extra.push_back(num);
            }
        }

        if (extra.empty()) return 0;

        sort(extra.begin(), extra.end());

        // Find minimum element overall (in both baskets)
        int global_min = *min_element(basket1.begin(), basket1.end());
        global_min = min(global_min, *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        for (int i = 0; i < extra.size() / 2; ++i) {
            cost += min(extra[i], 2 * global_min);
        }

        return cost;
    }
};
