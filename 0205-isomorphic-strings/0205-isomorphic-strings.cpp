class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> sp; // map from s to t
        unordered_map<char, char> tp; // map from t to s

        for (int i = 0; i < s.length(); i++) {
            char sc = s[i];
            char tc = t[i];

            // Check if there's already a mapping
            if (sp.count(sc)) {
                if (sp[sc] != tc) return false;
            } 
            else {
                sp[sc] = tc;
            }

            if (tp.count(tc)) {
                if (tp[tc] != sc) return false;
            } 
            else {
                tp[tc] = sc;
            }
        }

        return true;
    }
};
