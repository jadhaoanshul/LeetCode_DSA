class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        
        // Step 1: Put all elements into a set for O(1) lookup
        for (int num : nums) {
            set.add(num);
        }

        int longestStreak = 0;

        // Step 2: Loop through and find only the starts of sequences
        for (int num : set) {
            // check if it's the start of a sequence
            if (!set.contains(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (set.contains(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
}
