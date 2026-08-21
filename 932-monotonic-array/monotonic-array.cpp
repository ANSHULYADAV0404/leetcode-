class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isInc = true;
        bool isDec = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            // bool isInc=true;
            // bool isDec=true;
            if (nums[i] > nums[i + 1]) {
                isInc = false; // Increasing condition breaks
            }
            if (nums[i] < nums[i + 1]) {
                isDec = false; // Decreasing condition breaks
            }
        }
        if (isInc == true || isDec == true) {
            return true;
        } else {
            return false;
        }
    }
};