class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& grid, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == 1) {
            return;
        }
        
        vis[i][j] = true; // Mark the cell as visited
        
        dfs(i, j - 1, vis, grid, n, m);
        dfs(i - 1, j, vis, grid, n, m);
        dfs(i, j + 1, vis, grid, n, m);
        dfs(i + 1, j, vis, grid, n, m);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // 1. Flood-fill all 0s connected to the top and bottom borders
        for (int j = 0; j < m; ++j) {
            if (grid[0][j] == 0 && !vis[0][j]) {
                dfs(0, j, vis, grid, n, m);
            }
            if (grid[n - 1][j] == 0 && !vis[n - 1][j]) {
                dfs(n - 1, j, vis, grid, n, m);
            }
        }

        // 2. Flood-fill all 0s connected to the left and right borders
        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 0 && !vis[i][0]) {
                dfs(i, 0, vis, grid, n, m);
            }
            if (grid[i][m - 1] == 0 && !vis[i][m - 1]) {
                dfs(i, m - 1, vis, grid, n, m);
            }
        }

        // 3. Count remaining unvisited closed islands inside the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    dfs(i, j, vis, grid, n, m);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};