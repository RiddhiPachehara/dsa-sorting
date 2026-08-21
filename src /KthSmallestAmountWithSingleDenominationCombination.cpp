class Solution {
private:
    long long gcd(long long a, long long b) {
        return std::gcd(a, b);
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    long long countAmounts(long long target, const vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

        for (int mask = 1; mask < (1 << n); ++mask) {
            long long currentLcm = 1;
            int bitCount = 0;

            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    bitCount++;
                    currentLcm = lcm(currentLcm, coins[i]);
                }
            }

            long long multiples = target / currentLcm;
            if (bitCount % 2 == 1) {
                total += multiples;
            } else {
                total -= multiples;
            }
        }

        return total;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long minCoin = *min_element(coins.begin(), coins.end());
        long long low = 1;
        long long high = minCoin * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;  
            }
        }

        return ans;
    }
};
