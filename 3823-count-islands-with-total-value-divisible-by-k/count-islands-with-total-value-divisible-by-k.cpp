class Solution {
public:
    long long dfs(int i, int j, vector<vector<bool>>& vis,
                  vector<vector<int>>& grid, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] ||
            grid[i][j] == 0) {
            return 0;
        }

        vis[i][j] = true; // Mark the cell as visited
        long long current_sum = grid[i][j];
        current_sum += dfs(i, j - 1, vis, grid, n, m);
        current_sum += dfs(i - 1, j, vis, grid, n, m);
        current_sum += dfs(i, j + 1, vis, grid, n, m);
        current_sum += dfs(i + 1, j, vis, grid, n, m);
        return current_sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    long long totalValue = dfs(i, j, vis, grid, n, m);
                    if (totalValue % k == 0) {
                        islands++;
                    }
                }
            }
        }
        return islands;
    }
};