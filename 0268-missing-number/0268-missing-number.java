class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int i;
        for (i=0;i<n;i++){
            if(i!=nums[i])
                return i;
        }
        return n;
    }
}