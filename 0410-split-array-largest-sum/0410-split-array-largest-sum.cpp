class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;

        for (int k = 1; k <= m; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < i; ++j) {
                    dp[k][i] = min(dp[k][i], max(dp[k - 1][j], prefixSum[i] - prefixSum[j]));
                }
            }
        }

        return dp[m][n];
    }
};