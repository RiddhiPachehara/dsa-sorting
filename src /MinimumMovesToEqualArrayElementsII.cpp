 class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int median = nums[n / 2];
        long long totalMoves = 0;
        
        for (int num : nums) {
            totalMoves += abs(num - median);
        }
        
        return totalMoves;
    }
};
