class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int option1 = nums[n - 1] - nums[2];
        int option2 = nums[n - 2] - nums[1];
        int option3 = nums[n - 3] - nums[0];
        
        return min({option1, option2, option3});
    }
};
