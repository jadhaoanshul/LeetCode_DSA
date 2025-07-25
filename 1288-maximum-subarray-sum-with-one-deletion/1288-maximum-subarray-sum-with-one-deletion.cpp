class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if (arr.size()==1) return arr[0];
    int maxSum = arr[0];
    int One_Delete = 0;
    int No_delete = arr[0];
    for (int i = 1 ; i < arr.size(); i++)
    {
        // One_Delete là dãy con có tổng lớn nhất (từ 0 đến i) khi bỏ 1 phần tử 
        // No_Delete là dãy con có tổng lớn nhất (từ 0 đến i) // Kadane
        // Nếu bỏ phần tử arr[i] -> One_Delete = No_Delete (dãy con tổng max từ 0 -> i-1)
        One_Delete = max (No_delete, One_Delete + arr[i]);     
        No_delete = max(arr[i], No_delete + arr[i]);         // Kadane
        maxSum = max(maxSum,max(One_Delete, No_delete));
    }
    return maxSum;
    }
};