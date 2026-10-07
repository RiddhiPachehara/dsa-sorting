class Solution {
private:
    unordered_set<string> valid_expressions;

    void backtrack(int index, const string& s, string current, int balance, int rem_open, int rem_close) {
        if (balance < 0) return; 

        if (index == s.length()) {
            if (balance == 0 && rem_open == 0 && rem_close == 0) {
                valid_expressions.insert(current);
            }
            return;
        }

        char c = s[index];

        if (c == '(') {
            if (rem_open > 0) {
                backtrack(index + 1, s, current, balance, rem_open - 1, rem_close);
            }
            backtrack(index + 1, s, current + c, balance + 1, rem_open, rem_close);
        } else if (c == ')') {
            if (rem_close > 0) {
                backtrack(index + 1, s, current, balance, rem_open, rem_close - 1);
            }
            backtrack(index + 1, s, current + c, balance - 1, rem_open, rem_close);
        } else {
            backtrack(index + 1, s, current + c, balance, rem_open, rem_close);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int invalid_open = 0;
        int invalid_close = 0;

        for (char c : s) {
            if (c == '(') {
                invalid_open++;
            } else if (c == ')') {
                if (invalid_open > 0) {
                    invalid_open--;
                } else {
                    invalid_close++;
                }
            }
        }

        valid_expressions.clear();
        backtrack(0, s, "", 0, invalid_open, invalid_close);

        return vector<string>(valid_expressions.begin(), valid_expressions.end());
    }
};
