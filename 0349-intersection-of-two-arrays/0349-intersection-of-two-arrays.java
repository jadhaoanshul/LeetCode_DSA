public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        // Step 1: Create a HashSet to store unique elements from nums1
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums1) {
            set.add(num);
        }

        // Step 2: Create another HashSet to store the intersection
        HashSet<Integer> resultSet = new HashSet<>();
        
        // Step 3: Iterate through nums2 and check if the element is in set1
        for (int num : nums2) {
            if (set.contains(num)) {
                resultSet.add(num);
            }
        }

        // Step 4: Convert the resultSet to an array
        int[] result = new int[resultSet.size()];
        int index = 0;
        for (int num : resultSet) {
            result[index++] = num;
        }

        return result;
    }
}