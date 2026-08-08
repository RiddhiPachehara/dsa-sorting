class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> last_pos(m + 1, -1);
        last_pos[m] = n;

        int ptr = n - 1;
        for (int j = m - 1; j >= 0; j--) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            if (ptr >= 0) {
                last_pos[j] = ptr;
                ptr--;
            } else {
                last_pos[j] = -1;
            }
        }

        vector<int> result;
        int j = 0;
        bool changed = false;

        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                result.push_back(i);
                j++;
            } else if (!changed) {
                // Check if using our single allowed change at index i is valid
                if (j + 1 == m || (i + 1 <= last_pos[j + 1])) {
                    result.push_back(i);
                    changed = true;
                    j++;
                }
            }
        }

        if (result.size() < m) return {};

        return result;
    }
};
