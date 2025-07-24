class Solution {
public:
    //My first solution. I apologize for any mistakes I made
    int ans=INT_MAX;
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<unordered_set<int>> adj(n);
        for(auto &edge : edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(auto &edge : edges){
            
            int u=edge[0];
            int v=edge[1];
            adj[u].erase(v);
            adj[v].erase(u);
            
            int u_part=dfs(-1,u,adj,dp,nums);
            int v_part=dfs(-1,v,adj,dp,nums);
            dfs1(-1,u,u_part,v_part,adj,dp,nums);
            dfs1(-1,v,v_part,u_part,adj,dp,nums);
            adj[u].insert(v);
            adj[v].insert(u);
        }
        return ans;
    }
    int dfs(int par,int node,vector<unordered_set<int>> &adj,vector<vector<int>> &dp,vector<int> &nums){
        int curr=nums[node];
        for(auto &i : adj[node]){
            if(i!=par) curr=curr ^ dfs(node,i,adj,dp,nums);
        }
        if(par==-1) return curr; 
        return dp[par][node]=curr;
    }
    void dfs1(int par,int node,int thisPart,int otherPart,vector<unordered_set<int>> &adj,vector<vector<int>> &dp,vector<int> &nums){
        for(auto &i : adj[node]){
            int curr=dp[node][i];
            int left=(thisPart ^ curr);
            dp[i][node]=left;
            ans=min(ans,max(curr,max(left,otherPart))-min(curr,min(left,otherPart)));
            if(i!=par) dfs1(node,i,thisPart,otherPart,adj,dp,nums);
        }
    }
};