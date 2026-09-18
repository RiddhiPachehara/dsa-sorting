class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            if (first[ch] == -1) first[ch] = i;
            last[ch] = i;
        }

        vector<pair<int, int>> intervals;

        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;

            int left = first[i];
            int right = last[i];
            bool valid = true;

            for (int j = left; j <= right; ++j) {
                int ch = s[j] - 'a';
                if (first[ch] < left) {
                    valid = false;
                    break;
                }
                right = max(right, last[ch]);
            }

            if (valid) {
                intervals.push_back({left, right});
            }
        }

        sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        vector<string> ans;
        int prev_end = -1;

        for (const auto& [left, right] : intervals) {
            if (left > prev_end) {
                ans.push_back(s.substr(left, right - left + 1));
                prev_end = right;
            }
        }

        return ans;
    }
};
