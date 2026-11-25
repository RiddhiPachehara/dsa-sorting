class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        auto check = [&](int L) -> bool {
            if (L > n) return false;
            
            unsigned long long hash = 0;
            unsigned long long power = 1;
            const unsigned long long MOD = 1e9 + 7;
            const unsigned long long BASE = 313;
            
            for (int i = 0; i < L; ++i) {
                hash = (hash * BASE + (nums[i] + 1)) % MOD;
                if (i > 0) power = (power * BASE) % MOD;
            }
            
            unordered_map<unsigned long long, int> counts;
            counts[hash]++;
            
            for (int i = L; i < n; ++i) {
                hash = (hash + MOD - (nums[i - L] + 1) * power % MOD) % MOD;
                hash = (hash * BASE + (nums[i] + 1)) % MOD;
                counts[hash]++;
            }
            
            for (auto& pair : counts) {
                if (pair.second == 1) return true;
            }
            
            return false;
        };
        
        int low = 1, high = n;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }
        
        return ans;
    }
};
