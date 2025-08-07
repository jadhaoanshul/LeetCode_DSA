class Solution {
public:
    void helper(vector<string>& ans, string path, string num, int target, int idx, long long curr, long long prev){
        if(idx == num.size()){
            if(curr == target) ans.push_back(path);
            return;
        }
        for(int i = idx; i < num.size(); i++){
            if(i != idx && num[idx] == '0')break;
            string n = num.substr(idx, i-idx+1);
            long long nn = stoll(n);
            if(idx == 0){ 
                helper(ans, path + n, num, target, i+1, nn, nn);
            }else{
                helper(ans, path+'+'+n, num, target, i+1, curr+nn, nn);
                helper(ans, path+'-'+n, num, target, i+1, curr-nn, -nn);
                helper(ans, path+'*'+n, num, target, i+1, curr-prev+(prev*nn), prev*nn);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string>ans;
        helper(ans, "", num, target, 0, 0, 0);
        return ans;
    }
};