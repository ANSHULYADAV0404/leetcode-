class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int move = 0;
        // int sum = 0;
        sort(nums.begin(), nums.end());
        int median = nums[n / 2];

        for (int i = 0; i < n; i++) {
            // sum += nums[i];
            move += abs(nums[i] - median);
        }
        return move;
    }
};