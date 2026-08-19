class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedRows;

        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            reservedRows[row] |= (1 << (col - 1));
        }

        int totalGroups = (n - reservedRows.size()) * 2;

        const int LEFT_MASK   = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4); // Seats 2, 3, 4, 5
        const int MIDDLE_MASK = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6); // Seats 4, 5, 6, 7
        const int RIGHT_MASK  = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8); // Seats 6, 7, 8, 9

        for (const auto& [row, mask] : reservedRows) {
            bool leftFree   = (mask & LEFT_MASK) == 0;
            bool middleFree = (mask & MIDDLE_MASK) == 0;
            bool rightFree  = (mask & RIGHT_MASK) == 0;

            if (leftFree && rightFree) {
                totalGroups += 2;
            } else if (leftFree || middleFree || rightFree) {
                totalGroups += 1;
            }
        }

        return totalGroups;
    }
};
