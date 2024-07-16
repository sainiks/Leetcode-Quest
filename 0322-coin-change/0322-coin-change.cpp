class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n =amount;
        vector<int>dp(n+1,1e9);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(auto c: coins){
                if(i>=c and dp[i-c]!=1e9){
                    dp[i]=min(dp[i-c]+1,dp[i]);
                }
            }
        }
        if(dp[n]==1e9){
            dp[n]=-1;
        }
        return dp[n];
    }
};