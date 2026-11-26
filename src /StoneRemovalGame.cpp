class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        int k = 0; 
        
        while (n >= stones) {
            n -= stones;
            stones--;
            k++;
        }
        
        return k % 2 == 1;
    }
};
