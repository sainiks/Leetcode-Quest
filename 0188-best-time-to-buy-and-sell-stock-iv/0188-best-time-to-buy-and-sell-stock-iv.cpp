class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        int ans =0;
        for(int l=1;l<=k;l++){
            for(int i=2;i<=n;i++){
                dp[i][l]=dp[i-1][l];
                for(int j=1;j<=i-1;j++){
                    dp[i][l]=max(dp[i][l],dp[j-1][l-1]+prices[i-1]-prices[j-1]);
                    ans=max(ans,dp[i][l]);
                }
            }
        }
        return ans;
    }
};