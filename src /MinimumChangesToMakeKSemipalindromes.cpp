#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        

        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        
        vector<vector<int>> pal_cost(n, vector<int>(n, 0));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (len == 1) {
                    pal_cost[i][j] = 0;
                } else if (len == 2) {
                    pal_cost[i][j] = (s[i] == s[j] ? 0 : 1);
                } else {
                    pal_cost[i][j] = pal_cost[i + 1][j - 1] + (s[i] == s[j] ? 0 : 1);
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                int min_changes = 1e9;
                
                for (int d = 1; d * d <= len; ++d) {
                    if (len % d == 0) {
                        min_changes = min(min_changes, getSemiPalindromeChanges(s, i, j, d, pal_cost));
                        int d2 = len / d;
                        if (d2 < len) {
                            min_changes = min(min_changes, getSemiPalindromeChanges(s, i, j, d2, pal_cost));
                        }
                    }
                }
                cost[i][j] = min_changes;
            }
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int h = j - 1; h < i; ++h) {
                    if (h == 0) {
                        if (j == 1) {
                            dp[i][j] = min(dp[i][j], cost[0][i - 1]);
                        }
                    } else {
                        if (dp[h][j - 1] != 1e9) {
                            dp[i][j] = min(dp[i][j], dp[h][j - 1] + cost[h][i - 1]);
                        }
                    }
                }
            }
        }
        
        return dp[n][k];
    }

private:
    int getSemiPalindromeChanges(const string& s, int i, int j, int d, const vector<vector<int>>& pal_cost) {
        int total_changes = 0;
        int len = j - i + 1;
        int group_len = len / d;
        
        for (int offset = 0; offset < d; ++offset) {
            int start = i + offset;
            int end = j - (d - 1 - offset);
            
            int l = 0, r = group_len - 1;
            while (l < r) {
                int idx1 = start + l * d;
                int idx2 = start + r * d;
                if (s[idx1] != s[idx2]) {
                    total_changes++;
                }
                l++;
                r--;
            }
        }
        return total_changes;
    }
};
