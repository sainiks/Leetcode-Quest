// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2){
//         int m=text1.size(),n=text2.size();
//         vector<vector<int>>dp(m+1,vector<int>(n+1,0));
//         for(int i=1;i<=m;i++){
//             for(int j=1;j<=n;j++){
//                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 if(text1[i-1]==text2[j-1]){
//                     dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; ++i) {
            int prev = 0;
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j];
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }
        return dp[n];
    }
};