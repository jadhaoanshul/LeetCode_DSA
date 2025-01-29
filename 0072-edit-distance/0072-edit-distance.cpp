class Solution {
public:

    vector<vector<int>> dp;

    int solve(string& word1,string& word2,int i,int j){
        
        if(i==word1.size()){
            return word2.size()-j;
        }
        else if(j==word2.size()){
            return word1.size()-i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(word1[i]==word2[j]){
            return dp[i][j]= solve(word1,word2,i+1,j+1);
        }else{
            int del=solve(word1,word2,i+1,j);
            int rep=solve(word1,word2,i+1,j+1);
            int ins=solve(word1,word2,i,j+1);

            return dp[i][j]=min(del,min(rep,ins))+1;
        }
    }

    int minDistance(string word1, string word2) {
        dp.assign(word1.size(),vector<int>(word2.size(),-1));
       return  solve(word1,word2,0,0);
    }
};