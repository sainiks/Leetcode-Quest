// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(k+1,0));
//         int ans =0;
//         for(int l=1;l<=k;l++){
//             for(int i=2;i<=n;i++){
//                 dp[i][l]=dp[i-1][l];
//                 for(int j=1;j<=i-1;j++){
//                     dp[i][l]=max(dp[i][l],dp[j-1][l-1]+prices[i-1]-prices[j-1]);
//                     ans=max(ans,dp[i][l]);
//                 }
//             }
//         }
//         return ans;
//     }
// };



// More Optimized Solution

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        // If k >= n/2, it means we can make as many transactions as we want
        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    maxProfit += prices[i] - prices[i - 1];
                }
            }
            return maxProfit;
        }
        
        // DP table
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        
        for (int t = 1; t <= k; ++t) {
            int maxDiff = -prices[0];
            for (int i = 1; i < n; ++i) {
                dp[t][i] = max(dp[t][i - 1], prices[i] + maxDiff);
                maxDiff = max(maxDiff, dp[t - 1][i] - prices[i]);
            }
        }
        
        return dp[k][n - 1];
    }
};