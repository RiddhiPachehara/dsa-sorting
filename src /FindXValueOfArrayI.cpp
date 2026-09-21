class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);
        
        
        vector<long long> dp(k, 0);

        for (int i = 0; i < n; ++i) {
            int val = nums[i] % k;
            vector<long long> next_dp(k, 0);

            next_dp[val]++;

            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int next_rem = (1LL * r * val) % k;
                    next_dp[next_rem] += dp[r];
                }
            }

            for (int r = 0; r < k; ++r) {
                ans[r] += next_dp[r];
            }

            dp = move(next_dp);
        }

        return ans;
    }
};
