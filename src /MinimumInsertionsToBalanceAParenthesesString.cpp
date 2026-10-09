class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int needed_close = 0; 

        for (char c : s) {
            if (c == '(') {
                
                if (needed_close % 2 != 0) {
                    ans++;
                    needed_close--;
                }
                needed_close += 2;
            } else { 
                needed_close--;
                if (needed_close < 0) {
                    ans++;             
                    needed_close += 2; 
                }
            }
        }

        return ans + needed_close;
    }
};
