class Solution {
public:
    //int sum = 0;
    //int n = nums.size();
    //int minval = nums[0];
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int minval = nums[0];
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            // int j=i+1;
            minval = min(minval, nums[i]);
        }
        return sum - (minval * n);
    }
};