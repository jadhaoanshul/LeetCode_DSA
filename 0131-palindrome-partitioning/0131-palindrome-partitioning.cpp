class Solution {

    bool isPalindrome(string &str) {

        int len = str.length();
        int right = len - 1;
        int left = 0;

        while(left <= right) {

            if(str[left] != str[right]) return false;

            left++;
            right--;
        }

        return true;
    }
    void solve(int idx, string &str, vector<string> &ds, vector<vector<string>> &ans) {

        if(idx == str.length()) {
            ans.push_back(ds);
            return;
        }

        for(int i = idx; i < str.length(); i++) {

            string newStr = str.substr(idx, i - idx + 1);

            if(isPalindrome(newStr)) {
                ds.push_back(newStr);
                solve(i + 1, str, ds, ans);
                ds.pop_back();
            }
        } 
    }
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> ds;

        solve(0, s, ds, ans);

        return ans;

    }
};