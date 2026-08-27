class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        vector<vector<int>> pref_counts(n + 1, vector<int>(26, 0));
        pref_counts[0] = count;

        int matched_len = 0;
        for (int i = 0; i < n; ++i) {
            int target_char = target[i] - 'a';
            if (pref_counts[i][target_char] > 0) {
                pref_counts[i + 1] = pref_counts[i];
                pref_counts[i + 1][target_char]--;
                matched_len = i + 1;
            } else {
                break;
            }
        }

        for (int i = matched_len; i >= 0; --i) {
            if (i == n) continue;

            int target_char = target[i] - 'a';
            for (int c = target_char + 1; c < 26; ++c) {
                if (pref_counts[i][c] > 0) {
                    string result = target.substr(0, i);
                    result += (char)('a' + c);

                    vector<int> rem_count = pref_counts[i];
                    rem_count[c]--;

                    for (int ch = 0; ch < 26; ++ch) {
                        while (rem_count[ch] > 0) {
                            result += (char)('a' + ch);
                            rem_count[ch]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};
