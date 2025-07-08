class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        for(char c : s)
            m[c]++;
        for(char c : t)
            m[c]--;
        for(auto p : m) {
            if(p.second != 0)
                return p.first;
        }
        return ' '; 
    }
};
