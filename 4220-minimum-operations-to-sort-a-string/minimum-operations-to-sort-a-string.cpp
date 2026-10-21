class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // 0 operations: already sorted
        bool sorted = true;

        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }

        if (sorted)
            return 0;

        // For length 2, we cannot sort the whole string
        if (n == 2)
            return -1;

        // Find minimum and maximum character
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // 1 operation
        if (s[0] == mn || s[n - 1] == mx)
            return 1;

        // 2 operations
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx)
                return 2;
        }

        // 3 operations
        return 3;
    }
};