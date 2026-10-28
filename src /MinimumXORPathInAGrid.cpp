class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        
        dp[0][0].set(grid[0][0]);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int v = 0; v < 1024; ++v) {
                    if (dp[i][j].test(v)) {
                        if (i + 1 < m) {
                            dp[i + 1][j].set(v ^ grid[i + 1][j]);
                        }
                        if (j + 1 < n) {
                            dp[i][j + 1].set(v ^ grid[i][j + 1]);
                        }
                    }
                }
            }
        }
        
        for (int v = 0; v < 1024; ++v) {
            if (dp[m - 1][n - 1].test(v)) {
                return v;
            }
        }
        
        return -1;
    }
};
