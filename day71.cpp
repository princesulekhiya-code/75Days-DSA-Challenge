class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        // Remove consecutive duplicates to optimize
        string t = "";
        for (char c : s) {
            if (t.empty() || t.back() != c) t.push_back(c);
        }
        s = t;
        n = s.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) dp[i][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                dp[i][j] = dp[i+1][j] + 1;  // print s[i] separately

                for (int k = i + 1; k <= j; k++) {
                    if (s[i] == s[k]) {
                        dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k][j]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
