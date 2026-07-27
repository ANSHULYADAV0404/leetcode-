class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lp = 0, rp = n - 1, mid;
        while (lp <= rp) {
            mid = lp + (rp-lp) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                lp = mid + 1;
            } else {
                rp = mid - 1;
            }
        }
        return -1;
    }
};


