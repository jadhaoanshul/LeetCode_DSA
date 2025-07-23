vector<long long> p;
bool flag=true;
int mod = 1e9+7;
vector<vector<int>> dp(1500,vector<int>(301,-1));
void precompute(){
    for(int i = 1; i<=300; i++){
        for(int j = 1; j<=5; j++){
            p.push_back((long long)pow(i,j));
        }
    }
}
class Solution {
public:
    int helper(int index, int sum, int x){
        if(index>=(int)p.size()||sum<0)return 0;
        if(sum==p[index])return 1;
        if(dp[index][sum]!=-1)return dp[index][sum];
        int ans = 0;
        for(int i = index+5; i<p.size(); i+=5){
            if(p[i]-p[index]>sum)break;
            ans=(ans+helper(i,sum-p[index],x))%mod;
        }
        return dp[index][sum]=ans%mod;
    }
    int numberOfWays(int n, int x) {
        if(flag){
            precompute();
            flag=false;
        }
        int ans = 0;
        for(int i = x-1; i<p.size(); i+=5){
            if(p[i]>n)break;
            ans=(ans+helper(i,n,x))%mod;
        }
        return ans%mod;
    }
};