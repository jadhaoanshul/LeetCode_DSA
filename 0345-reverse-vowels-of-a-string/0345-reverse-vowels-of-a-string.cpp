class Solution {
public:
    bool isVowel(char& ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
        } else {
            return false;
        }
    }
    string reverseVowels(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            if(!isVowel(s[l]))
                l++;
            else if(!isVowel(s[r]))
                r--;
            else{
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};