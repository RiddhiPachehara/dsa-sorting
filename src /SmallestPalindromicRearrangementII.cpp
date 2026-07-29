class Solution {
private:
    const long long MAX_K = 1e6 + 1;

    long long nCr(long long n, long long r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;

        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
            if (res >= MAX_K) return MAX_K;
        }
        return res;
    }

    long long countArrangements(const vector<int>& count) {
        long long total = 0;
        for (int c : count) total += c;

        long long res = 1;
        for (int c : count) {
            if (c > 0) {
                res *= nCr(total, c);
                if (res >= MAX_K) return MAX_K;
                total -= c;
            }
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string mid = "";
        vector<int> halfCount(26, 0);
        int halfLen = 0;

        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 == 1) {
                mid += (char)('a' + i);
            }
            halfCount[i] = freq[i] / 2;
            halfLen += halfCount[i];
        }

        long long totalPermutations = countArrangements(halfCount);
        if (k > totalPermutations) {
            return "";
        }

        string leftHalf = "";
        for (int pos = 0; pos < halfLen; ++pos) {
            for (int i = 0; i < 26; ++i) {
                if (halfCount[i] == 0) continue;

                halfCount[i]--;
                long long arrangements = countArrangements(halfCount);

                if (k <= arrangements) {
                    leftHalf += (char)('a' + i);
                    break;
                } else {
                    k -= arrangements;
                    halfCount[i]++;
                }
            }
        }

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        return leftHalf + mid + rightHalf;
    }
};
