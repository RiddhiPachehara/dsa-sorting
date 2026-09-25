class Solution {
private:
    set<string> multiplySets(const set<string>& s1, const set<string>& s2) {
        if (s1.empty()) return s2;
        if (s2.empty()) return s1;
        set<string> res;
        for (const string& str1 : s1) {
            for (const string& str2 : s2) {
                res.insert(str1 + str2);
            }
        }
        return res;
    }

    set<string> evaluate(const string& expr, int start, int end) {
        set<string> res;               
        vector<set<string>> groups;   
        groups.push_back({});

        int layer = 0;
        int block_start = 0;

        for (int i = start; i <= end; ++i) {
            if (expr[i] == '{') {
                if (layer == 0) {
                    block_start = i + 1;
                }
                layer++;
            } else if (expr[i] == '}') {
                layer--;
                if (layer == 0) {
                    set<string> sub_res = evaluate(expr, block_start, i - 1);
                    groups.back() = multiplySets(groups.back(), sub_res);
                }
            } else if (expr[i] == ',' && layer == 0) {
                for (const string& word : groups.back()) {
                    res.insert(word);
                }
                groups.back().clear();
            } else if (layer == 0) {
                set<string> char_set = {string(1, expr[i])};
                groups.back() = multiplySets(groups.back(), char_set);
            }
        }

        for (const string& word : groups.back()) {
            res.insert(word);
        }

        return res;
    }

public:
    vector<string> braceExpansionII(string expression) {
        set<string> unique_words = evaluate(expression, 0, expression.length() - 1);
        return vector<string>(unique_words.begin(), unique_words.end());
    }
};
