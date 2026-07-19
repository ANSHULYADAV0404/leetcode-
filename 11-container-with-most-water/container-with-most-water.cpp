class Solution {
public:
    int maxArea(vector<int>& height) {
        int wid = 0, lp = 0, rp = height.size() - 1, maxwater = 0, area = 0,
            h = 0;
        while (lp < rp) {
            wid = rp - lp;
            h = min(height[lp], height[rp]);
            area = wid * h;
            maxwater = max(area, maxwater);
            if (height[lp] < height[rp])
                lp++;
            else
                rp--;
        }
        return maxwater;
    }
};