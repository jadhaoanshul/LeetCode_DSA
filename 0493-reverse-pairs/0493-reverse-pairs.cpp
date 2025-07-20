class Solution {
public:
    void merge(vector<int>& nums, int s, int e, int& count) {
        int mid = s + (e - s) / 2;

        int len1 = mid - s + 1;
        int len2 = e - mid;
        vector<long long> arr1(len1, 0);
        vector<long long> arr2(len2, 0);

        int ptr = s;
        for (int i = 0; i < len1; i++) {
            arr1[i] = nums[ptr++];
        }

        for (int i = 0; i < len2; i++) {
            arr2[i] = nums[ptr++];
        }

        int j = 0;
        for (int i = 0; i < len1; i++) {
            while (j < len2 && arr1[i] > 2LL * arr2[j]) {
                j++;
            }
            count += j;
        }

        ptr = s;
        int i = 0;
        j = 0;
        while (i < len1 && j < len2) {
            if (arr1[i] <= arr2[j]) {
                nums[ptr++] = arr1[i++];
            } else {
                nums[ptr++] = arr2[j++];
            }
        }

        while (i < len1) {
            nums[ptr++] = arr1[i++];
        }

        while (j < len2) {
            nums[ptr++] = arr2[j++];
        }
    }

    void merge_sort(vector<int>& nums, int s, int e, int& count) {
        if (s >= e) return;

        int mid = s + (e - s) / 2;
        merge_sort(nums, s, mid, count);
        merge_sort(nums, mid + 1, e, count);
        merge(nums, s, e, count);
    }

    int reversePairs(vector<int>& nums) {
        int count = 0;
        merge_sort(nums, 0, nums.size() - 1, count);
        return count;
    }
};