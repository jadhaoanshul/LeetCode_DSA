class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count =0 ;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                count = 0;
                break;
            }
            else if(nums[i]<0)
                count++;
            else if(nums[i]>0)
                count+=2;
        }
        if (count==0)
            return 0;
        else if(count%2==0)
            return 1;
        else
            return -1;
    }
};