class Solution {
public:
    void comb(int ind, vector<int>& cand, int t, vector<vector<int>>& res, vector<int>& ds) {
        if (t == 0) {
            res.push_back(ds);
            return;
        }

        for (int i = ind; i < cand.size(); i++) {
            if (i > ind && cand[i] == cand[i - 1]) continue;
            if (cand[i] > t) break;

            ds.push_back(cand[i]);
            comb(i + 1, cand, t - cand[i], res, ds);  
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // required to handle duplicates
        vector<vector<int>> res;
        vector<int> ds;
        comb(0, candidates, target, res, ds);
        return res;
    }
};
