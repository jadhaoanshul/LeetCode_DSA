class Solution {
public:
    int maximumCount(vector<int>& nums) {
         int c=0,n=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]>0)
                c++;
            else if(nums[i]<0)
                n++;
        }
        if(c>n)
            return c;
        else 
            return n;
    }
};