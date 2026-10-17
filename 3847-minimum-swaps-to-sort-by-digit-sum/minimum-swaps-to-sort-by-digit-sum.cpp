class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Pair to store {digit_sum, original_value} along with their initial
        // indices
        vector<pair<pair<int, int>, int>> v(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;
            // Correct way to find the sum of digits
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            // Store { {digit_sum, original_value}, original_index }
            v[i] = {{sum, nums[i]}, i};
        }
        sort(v.begin(), v.end());

        // Find minimum swaps to sort using cycle detection
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            // If already visited or already in the correct position
            if (visited[i] || v[i].second == i) {
                continue;
            }

            // Count the size of the cycle
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = v[j].second;
                cycle_size++;
            }

            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }

        return swaps;
    }
};
