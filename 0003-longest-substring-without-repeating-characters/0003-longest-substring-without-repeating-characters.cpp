class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0,l=0,r=0;
        //map<char,int> hash[256] = -1;
        int hash[256];
        fill(hash, hash+256, -1);
        while(r<n){
            if(hash[s[r]]!=-1)
            {
                if(hash[s[r]]>=l){
                    l = hash[s[r]] +1;
                }
            }         
                int len = r - l + 1;
                maxlen = max(maxlen, len);
            hash[s[r]] = r;
            r++;
        }

        return maxlen;
    }
};
