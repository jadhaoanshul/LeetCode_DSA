class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        char r[n];
        int j=0;
        for(int i=n-1;i>=0;i--){
            r[j] = s[i];
            j++;
       }
       for(int i=0; i<n; i++){
            s[i]=r[i];
       }

    }
};