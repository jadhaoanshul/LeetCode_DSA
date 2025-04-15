class Solution {
public:
    
    long long goodTriplets(vector<int>& n1, vector<int>& n2) {
        int n = size(n1); vector<int> bt(n + 1), ids(n); long long r = 0;
        for (int i = 0; i < n; ++i) ids[n2[i]] = i;
        for (int i = 0; i < n; ++i) {
            int mid = ids[n1[i]], l = 0, j = 0;
            j = mid + 1; while (j > 0) l += bt[j], j -= j & (-j);
            j = mid + 1; while (j <= n) bt[j]++, j += j & (-j);
            r += 1LL * l * (n - 1 - mid - (i - l));
        } return r;
    }

};