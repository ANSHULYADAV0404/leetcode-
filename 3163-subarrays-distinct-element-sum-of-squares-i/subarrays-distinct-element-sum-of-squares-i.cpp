class Solution {
public:
    void helper(vector<int>& nums, int s, int e, int& sum) {
        if (s == nums.size()) {
            return;
        }
        if (e == nums.size()) {
            helper(nums, s + 1, s + 1, sum);
            return;
        }
        unordered_set<int> sets;
        for (int i = s; i <= e; i++) {
            sets.insert(nums[i]);
        }
        int count = sets.size();
        sum += count * count;
        helper(nums, s, e + 1, sum);
    }
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        helper(nums, 0, 0, sum);
        return sum;
    }
};