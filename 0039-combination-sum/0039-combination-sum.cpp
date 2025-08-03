class Solution {
public:
    void comb(int ind, vector<int>& cand, int t, vector<vector<int>>& res, vector<int>& ds){
        if(ind == cand.size()){
            if(t == 0)
                res.push_back(ds);
            return;
        }

        if(cand[ind] <= t){
            ds.push_back(cand[ind]);
            comb(ind, cand, t - cand[ind], res, ds);
            ds.pop_back();
        }
        comb(ind + 1, cand, t, res, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        comb(0, candidates, target, res, ds);
        return res;
    }
};