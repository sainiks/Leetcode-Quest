class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=min(k,i);j++){
                int mx=0,mxNum=0;
                for(int l=1;l<=k;l++){
                    mx=max(mx,dp[i-j][l]);
                }
                for(int l=max(i-j+1,0);l<=i;l++){
                    mxNum=max(mxNum,nums[l-1]);
                }
                dp[i][j]=max(dp[i][j],mx+mxNum*j);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};