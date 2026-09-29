class Solution {
private:
    int m, n;
    bool visited[100][100][101];

    bool dfs(int r, int c, int bal, const vector<vector<char>>& grid) {
        bal += (grid[r][c] == '(' ? 1 : -1);

        if (bal < 0 || bal > (m + n) / 2 || visited[r][c][bal]) {
            return false;
        }

        visited[r][c][bal] = true;

        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }

        if (c + 1 < n && dfs(r, c + 1, bal, grid)) {
            return true;
        }

        if (r + 1 < m && dfs(r + 1, c, bal, grid)) {
            return true;
        }

        return false;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        return dfs(0, 0, 0, grid);
    }
};
