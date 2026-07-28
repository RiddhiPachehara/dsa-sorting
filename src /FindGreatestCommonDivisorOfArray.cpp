class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_num = nums[0];
        int max_num = nums[0];

        for (int x : nums) {
            min_num = min(min_num, x);
            max_num = max(max_num, x);
        }

        return std::gcd(min_num, max_num);
    }
};
