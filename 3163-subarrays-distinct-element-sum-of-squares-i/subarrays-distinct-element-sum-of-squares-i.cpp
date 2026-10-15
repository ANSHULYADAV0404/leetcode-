class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        
        // Generate all possible subarrays using nested loops
        for (int i = 0; i < n; i++) {
            unordered_set<int> distinctElements;
            for (int j = i; j < n; j++) {
                // Add current element to the set for subarray nums[i...j]
                distinctElements.insert(nums[j]);
                
                // Get distinct count
                int count = distinctElements.size();
                
                // Add square of the distinct count to totalSum
                totalSum += count * count;
            }
        }
        
        return totalSum;
    }
};