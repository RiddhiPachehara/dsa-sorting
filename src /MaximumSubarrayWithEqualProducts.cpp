class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        const long long MAX_PROD = 25200;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                prod *= nums[j];
                if (prod > MAX_PROD) break;

                g = (j == i) ? nums[j] : gcd(g, (long long)nums[j]);
                l = (j == i) ? nums[j] : lcm(l, (long long)nums[j]);

                if (prod == l * g) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};
