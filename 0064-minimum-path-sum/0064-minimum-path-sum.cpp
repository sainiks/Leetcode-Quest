class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        dp[0][0]=grid[0][0];
        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0)continue;
                int sum=1e9;
                if(i-1>=0){
                    sum=min(dp[i-1][j],sum);
                }
                if(j-1>=0){
                    sum=min(sum,dp[i][j-1]);
                }
                dp[i][j]=sum+grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};