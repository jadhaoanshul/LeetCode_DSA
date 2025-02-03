class Solution {
public:
vector<vector<int>> subset(vector<int> arr,int index,int n,vector<vector<int> >& ans,vector<int> temp){
    if(index == n){
        ans.push_back(temp);
        return ans ;
    }
    subset(arr,index+1,n,ans,temp);
    temp.push_back(arr[index]);
    subset(arr,index+1,n,ans,temp);
        return ans ;
}
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ans;  
      vector<int> temp;
      int n = nums.size();
      int index =0;
      return subset(nums,index,n,ans,temp);
      
    }
};