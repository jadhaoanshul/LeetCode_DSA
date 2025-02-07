class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<long, int> mp;    // color: freq
        unordered_map<int, int> balls;  // ball: color
        int s = queries.size();
        vector<int> res(s, 0);
        int cnt = 0;

        for (int i = 0; i < s; i++) {
            int ball = queries[i][0];
            int col = queries[i][1];

            if (balls[ball]) {
                mp[balls[ball]]--;
                if (!mp[balls[ball]]) {
                    cnt--;
                }
            }

            balls[ball] = col;
            mp[col]++;

            if (mp[col] == 1) {
                cnt++;
            }

            res[i] = cnt;
        }

        return res;
    }
};