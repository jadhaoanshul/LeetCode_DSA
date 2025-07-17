class Solution {
    public int lengthOfLIS(int[] nums) {
        ArrayList<Integer> temp = new ArrayList<>();
        
        for (int num : nums) {
            int idx = Collections.binarySearch(temp, num);
            if (idx < 0) idx = -(idx + 1);
            
            if (idx == temp.size()) {
                temp.add(num);
            } else {
                temp.set(idx, num);
            }
        }

        return temp.size();
    }
}
