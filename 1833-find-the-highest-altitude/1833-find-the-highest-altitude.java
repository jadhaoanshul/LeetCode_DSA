class Solution {
    public int largestAltitude(int[] gain) {
        // Initialize an array to store altitudes
        int[] nums = new int[gain.length + 1];
        nums[0] = 0; // Initial altitude is 0

        // Calculate cumulative altitudes
        for (int i = 0; i < gain.length; i++) {
            nums[i + 1] = nums[i] + gain[i];
        }

        // Find the largest altitude
        int larg = Integer.MIN_VALUE; // Initialize to minimum possible value
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] > larg) {
                larg = nums[j];
            }
        }
        return larg;
    }
}
