class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int bestval = nums[0];
        int worstval = nums[0];
        int ans = nums[0];
        int sum = nums[0];
        int minans=nums[0];
        for (int i = 1; i < nums.size(); i++) {

            int a = nums[i] + bestval;
            int b = nums[i];
            bestval = max(a, b);
            ans = max(bestval, ans);
            int c= nums[i]+worstval;
            int d = nums[i];

            worstval = min(d, c);
            minans = min(worstval, minans);
            sum+=nums[i];
        }
        if (ans < 0)
            return ans;
        return max(ans, sum - minans);
        //return ans;
    }
};