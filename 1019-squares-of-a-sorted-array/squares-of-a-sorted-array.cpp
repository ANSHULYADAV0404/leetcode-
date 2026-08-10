class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int lp = 0, rp = n - 1;
        int pos = n - 1; // Peeche se fill karenge

        while (lp <= rp) {
            int leftSquare = nums[lp] * nums[lp];
            int rightSquare = nums[rp] * nums[rp];

            if (leftSquare > rightSquare) {
                ans[pos] = leftSquare;
                lp++;
            } else {
                ans[pos] = rightSquare;
                rp--;
            }
            pos--;
        }

        return ans;
    }
};