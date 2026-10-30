class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldcolor,
             int newcolor) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() ||
            image[sr][sc] == newcolor || image[sr][sc] != oldcolor) {
            return;
        }
        image[sr][sc] = newcolor;
        dfs(image, sr - 1, sc, oldcolor, newcolor);
        dfs(image, sr + 1, sc, oldcolor, newcolor);
        dfs(image, sr, sc - 1, oldcolor, newcolor);
        dfs(image, sr, sc + 1, oldcolor, newcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};