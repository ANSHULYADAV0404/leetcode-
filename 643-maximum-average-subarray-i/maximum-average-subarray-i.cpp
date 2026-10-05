class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        //double maxsum = sum;
        for (int i = 0; i < k; i++) {
            sum = sum + nums[i];
        }
        double maxsum = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k]; // Naya element add, purana minus
            maxsum = max(maxsum, sum);
        }
        return maxsum / k;
    }
};