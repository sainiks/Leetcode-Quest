class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pref(n+1,0);
        for(int i=1; i<=n;i++){
            pref[i]=pref[i-1]+nums[i-1];
        }
        vector<vector<int>>dp(n+1,vector<int>(k+1,1e9));
        for(int i=0;i<=k;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                if(i==1){
                    dp[j][i]=pref[j]-pref[0];
                }else{
                    for(int l=j;l>0;l--){
                        int sum=pref[j]-pref[l-1];
                        dp[j][i]=min(dp[j][i],max(dp[l-1][i-1],sum));
                    }
                }
            }
        }
        return dp[n][k];
    }
};