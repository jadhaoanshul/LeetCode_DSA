class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int i=0;
    int sum=0;
    int maxsum=INT_MIN;
    int index=0;
    int negsum=0;
    while(i<nums.size())
    {
      sum+=nums[i];
      if(sum<0)
      { 
        for(int j=i;j>=index;j--)
        {
            if(nums[j]>=sum)
            {
                negsum=nums[j];
            }
        }
        if(negsum>maxsum)
        {
            maxsum=negsum;
        }
        
          sum=0;
          index=i;
      }
      else if(sum>maxsum)
      {
        maxsum=sum;
      }
      i++;
    }

    return maxsum;
    }
};