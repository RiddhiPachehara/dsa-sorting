class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        
       
        vector<int> min_len(n, INF);
        
        int left = 0;
        int current_sum = 0;
        int ans = INF;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];

            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }

            if (right > 0) {
                min_len[right] = min_len[right - 1];
            }

            if (current_sum == target) {
                int curr_len = right - left + 1;

                
                if (left > 0 && min_len[left - 1] != INF) {
                    ans = min(ans, curr_len + min_len[left - 1]);
                }

                min_len[right] = min(min_len[right], curr_len);
            }
        }

        return ans == INF ? -1 : ans;
    }
};
