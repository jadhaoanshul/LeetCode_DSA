class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> st;
        for(char c: s){
            st[c]++;
        }
         int firstFreq = st.begin()->second;

        // Check if all frequencies are the same
        for (auto it : st) {
            if (it.second != firstFreq) {
                return false;
            }
        }
        return true;
    }
};