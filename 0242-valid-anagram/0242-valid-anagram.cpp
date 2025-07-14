class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length()) return false;
        map<char,int> sp,tp;
        for(char c:s) sp[c]++;
        for(char c:t) tp[c]++;
        return sp==tp;
    }
};