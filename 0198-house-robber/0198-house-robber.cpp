class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            int sum=0;
            if(i-2>=0){
                sum=max(sum,dp[i-2]);
            }
            if(i-3>=0){
                sum=max(sum,dp[i-3]);
            }
            dp[i]=sum+nums[i];
        }
        int ans=dp[n-1];
        if(n-2>=0){
            ans=max(ans,dp[n-2]);
        }
        return ans;
    }
};