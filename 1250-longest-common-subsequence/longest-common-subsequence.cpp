class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length(), m = s2.length();

        dp[0][0] = s1[0] == s2[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = (s1[i] == s2[0]);
            dp[i][0] = max(dp[i-1][0], dp[i][0]);
        }
        for (int i = 1; i < m; i++) {
            dp[0][i] = (s1[0] == s2[i]);
            dp[0][i] = max(dp[0][i-1], dp[0][i]);
        }

        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (s1[i] == s2[j]) dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
            }

        return dp[n-1][m-1];
    }
};