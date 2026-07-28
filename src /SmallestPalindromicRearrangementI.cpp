class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        
        string half = s.substr(0, n / 2);
        
        sort(half.begin(), half.end());
        
        string result = half;
        if (n % 2 == 1) {
            result += s[n / 2];
        }
        
        string reversed_half = half;
        reverse(reversed_half.begin(), reversed_half.end());
        result += reversed_half;
        
        return result;
    }
};
