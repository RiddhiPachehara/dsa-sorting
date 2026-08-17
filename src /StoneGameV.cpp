class Solution {
private:
    int memo[501][501];
    vector<int> pref;

    int getSum(int i, int j) {
        return pref[j + 1] - pref[i];
    }

    int solve(int i, int j) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int maxScore = 0;

        for (int k = i; k < j; ++k) {
            int leftSum = getSum(i, k);
            int rightSum = getSum(k + 1, j);

            if (leftSum < rightSum) {
                maxScore = max(maxScore, leftSum + solve(i, k));
            } else if (leftSum > rightSum) {
                maxScore = max(maxScore, rightSum + solve(k + 1, j));
            } else {
                maxScore = max(maxScore, leftSum + max(solve(i, k), solve(k + 1, j)));
            }
        }

        return memo[i][j] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        pref.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }

        fill(&memo[0][0], &memo[0][0] + 501 * 501, -1);

        return solve(0, n - 1);
    }
};
