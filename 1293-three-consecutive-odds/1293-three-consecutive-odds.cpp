class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int c=0;
        for(int i=0; i<arr.size();i++){
            if(arr[i]%2!=0){
                c++;
                if(c==3)
                    break;
            }
            else  
                c=0;
        }
        if(c==3) return true;
        else return false;

    }
};