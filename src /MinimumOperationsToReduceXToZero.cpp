class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        long long target = total_sum - x;

        if (target < 0) return -1;
        if (target == 0) return n;

        int left = 0;
        long long current_sum = 0;
        int max_len = -1;

        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];

            while (current_sum > target && left <= right) {
                current_sum -= nums[left];
                left++;
            }

            if (current_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }

        return max_len == -1 ? -1 : n - max_len;
    }
};
